/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/05 13:15:23 by lrocigno         ###   ########.fr       */
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

static int	printf_type(const char *str, va_list args)
{
	char	*print;
	size_t	p_sz;
	t_fspec	*type;

	type = pf_settype(str, args);
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
	str = ft_strchr(str + 1, type->s);
	pf_delfspec(&type);
	return (p_sz);
}

int	ft_printf(const char *str, ...)
{
	int		cnt;
	va_list	args;

	if (pf_error(str))
		return (0);
	cnt = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			cnt += printf_type(str, args);
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
