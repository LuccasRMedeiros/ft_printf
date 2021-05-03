/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/03 17:54:38 by lrocigno         ###   ########.fr       */
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

int	ft_printf(const char *str, ...)
{
	int		cnt;
	va_list	args;
	t_fspec	*type;

	cnt = 0;
	va_start(args, str);
	type = NULL;
	while (*str)
	{
		if (*str == '%')
		{
			type = pf_settype(str, args);
			if (!type->init)
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
	va_end(args);
	return (cnt);
}
