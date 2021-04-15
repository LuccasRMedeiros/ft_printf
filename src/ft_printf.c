/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/15 08:57:14 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Printf should receive indenfinite arguments and interpolate them into the   -
** received string (if necessary and in the correct format) and print it in the-
**  terminal.
** Upon a succesfull execution, printf returns the amount of printed           -
** characters
*/

#include <ft_printf.h>
#include <stdio.h>

static int		ft_atoi_t_adv(char **string)
{
	int	acc;

	acc = 0;
	while (ft_isdigit(**string) && **string)
	{
		acc = (len * 10) + ft_atoi(&**string);
		**++string;
	}
	return (acc);
}

static f_type	*set_type(char **string, va_list args)
{
	f_type *ret;

	ret = pf_newfspec();
	while (ret->init && **string)
	{
		if (ft_strhvchr(c, P_FLAGS) && !(ft_strhvchr(c, ret->flags)))
			ret->flags[ft_strlen(ret->flags)] = c;
		else if (ft_strhvchr(c, P_WIDTH) && !(ret->precision))
			ret->width = c == * ? va_arg(args, int) : ft_atoi_t_adv(&*string);
		else if (c == '.')
			ret->precision = true;
		else if (ft_strhvchr(c, P_WIDTH))
			ret->width = c == * ? va_arg(args, int) : ft_atoi_t_adv(&*string);
		else if (ft_strhvchr(c, P_SPECS))
		{
			ret->init = false;
			ret->specifier = c;
		}
		**++string;
	}
	ret->data = pf_parser(args, ret);
	ret->length = ft_strlen(type->data);
	return (ret);
}

static void		printf_type(t_fspec *type)
{
	char *print;

	print = pf_textformat(type);
	if (!print)
		return ;
	ft_putstr_fd(print, 1);
}

int				ft_printf(const char *string, ...)
{
	size_t	cnt;
	va_list	args;
	t_fspec	*type;

	cnt = 0;
	va_start(args, string);
	type = NULL;
	while (*string)
	{
		if (*string == '%')
		{
			type = set_type(&string, type);
			printf_type(type);
			cnt += type->size;
			pf_delfspec(&type);
		}
		else
		{
			ft_putchar_fd(*string, 1);
			++cnt;
		}
		*++string;
	}
	va_end(args);
	return (cnt);
}
