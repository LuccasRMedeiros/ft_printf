/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/15 23:18:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Printf should receive indenfinite arguments and interpolate them into the   -
** received string (if necessary and in the correct format) and print it in the-
**  terminal.
** Upon a succesfull execution, printf returns the amount of printed           -
** characters.
** 
*/

#include <ft_printf.h>
#include <stdio.h>

static int		ft_atoi_t_adv(char **str)
{
	int	acc;

	acc = 0;
	while (ft_isdigit(**str) && **str)
	{
		acc = (acc * 10) + ft_atoi(&**str);
		*++str;
	}
	return (acc);
}

static size_t	calc_size(bool p, int w, int l, char s, char *dt)
{
	size_t ret;
	size_t dt_len;

	dt_len = ft_strlen(dt);
	if (ft_strhvchr(P_ALP, &s))
		ret = p ? l : dt_len;
	else
		ret = p && l > dt_len ? l : dt_len;
	ret = ret > w ? ret : w;
	return (ret);
}

static t_fspec	*set_type(char **str, va_list args)
{
	t_fspec *ret;

	ret = pf_newfspec();
	while (ret->init && **str)
	{
		if (ft_strhvchr(P_FLAGS, &**str) && !(ft_strhvchr(ret->fs, &**str)))
			ret->fs[ft_strlen(ret->fs)] = **str;
		else if (ft_strhvchr(P_WIDTH, &**str) && !(ret->p))
			ret->w = **str == * ? va_arg(args, int) : ft_atoi_t_adv(&*str);
		else if (**str == '.')
			ret->p = true;
		else if (ft_strhvchr(P_LNGTH, &**str))
			ret->w = **str == * ? va_arg(args, int) : ft_atoi_t_adv(&*str);
		else if (ft_strhvchr(P_SPECS, &**str))
		{
			ret->init = false;
			ret->s = **str;
		}
		*++str;
	}
	ret->dt = pf_parser(args, ret);
	ret->sz = calc_size(ret->p, ret->w, ret->l, ret->s, ret->dt);
	return (ret);
}

static void		printf_type(t_fspec *type)
{
	char *print;

	print = pf_textformat(type);
	if (!print)
		return ;
	ft_putstr_fd(print, 1);
	free(print);
}

int				ft_printf(const char *str, ...)
{
	size_t	cnt;
	va_list	args;
	t_fspec	*type;

	cnt = 0;
	va_start(args, str);
	type = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			type = set_type(&str, args);
			printf_type(type);
			cnt += type->size;
			pf_delfspec(&type);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			++cnt;
		}
		++str;
	}
	va_end(args);
	return (cnt);
}
