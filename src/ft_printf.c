/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/05 14:02:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Printf should receive indenfinite arguments and interpolate them into the   -
** received string (if necessary and in the correct format) and print it in the-
**  terminal.
** Upon a succesfull execution, printf returns the amount of printed           -
** characters.
*/

#include <ft_printf.h>
#include <stdio.h>

static int	printf_type(t_fspec *type)
{
	char	*print;
	size_t	p_sz;

	print = pf_textformat(type);
	if (!print || type->init)
	{
		pf_delfspec(&type);
		return (0);
	}
	p_sz = 0;
	while (p_sz < type->w)
	{
		ft_putchar_fd(print[p_sz], 1);
		++p_sz;
	}
	free(print);
	pf_delfspec(&type);
	return (p_sz);
}

static int	printf_char(const char *str, va_list args)
{
	size_t	cnt;
	t_fspec	*type;

	cnt = 0;
	type = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			type = pf_settype(str, args);
			str = ft_strchr(str + 1, type->s);
			cnt += printf_type(type);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			++cnt;
		}
		++str;
	}
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	int		cnt;
	va_list	args;

	if (pf_error(str))
		return (0);
	va_start(args, str);
	cnt = printf_char(str, args);
	va_end(args);
	return (cnt);
}
