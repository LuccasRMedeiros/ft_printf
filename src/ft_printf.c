/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocignoS <lrocigno@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/25 11:53:43 by lrocignoS        ###   ########.fr       */
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

static void	printf_type(t_fspec *type)
{
	char	*print;

	print = pf_textformat(type);
	if (!print)
		return ;
	ft_putstr_fd(print, 1);
	free(print);
	pf_delfspec(&type);
}

int	ft_printf(const char *str, ...)
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
			type = pf_settype(str, args);
			cnt += type->w;
			str = ft_strchr(str + 1, type->s);
			printf_type(type);
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
