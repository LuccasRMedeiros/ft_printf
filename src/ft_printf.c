/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/09 13:20:27 by lrocigno         ###   ########.fr       */
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

static unsigned int	type_check(unsigned int type, char c)
{
	size_t			i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (P_CONVS[i] && P_CONVS[i] != c)
		i++;
	if (i > 8 || (type == 1 && i == 8) || (i < 8 && type == 0))
		ret	= 0;
	else if (type == 0 && i == 8)
		ret = 1;
	else if (type == 1 && (i >= 0 && i <= 8))
		ret = 9 - i;
	return (ret);
}

int					ft_printf(const char *string, ...)
{
	size_t			sti;
	size_t			cnt;
	unsigned int	type;
	va_list			args;
	char			*data;

	sti = 0;
	cnt = 0;
	type = 0;
	va_start(args, string);
	while (string[sti])
	{
		type = type_check(type, string[sti]);
		cnt = type == 0 ? cnt + 1 : cnt + 0;
		if (type == 0)
			ft_putchar_fd(string[sti], 1);
		else if (type >= 2)
		{
			data = pf_parser(args, type);
			cnt += ft_strlen(data);
			ft_putstr_fd(data, 1);
			free(data);
		}
		sti++;
	}
	va_end(args);
	return (cnt);
}
