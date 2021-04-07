/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/07 11:42:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Printf should receive indenfinite arguments and interpolate them into the   -
** received string (if necessary and in the correct format) and print it in the-
**  terminal.
** Upon a succesfull execution, printf returns the amount of printed           -
** characters
*/

#include <libft.h>
#include <stdio.h>

static int	stts_updt(unsigned int status, char c)
{
	size_t	i;

	i = 0;
	while (P_CONVS[i] && P_CONVS[i] != c)
		i++;
	if (i > 8 || (status == 1 && i == 8))
		status == 0;
	else if (!status && (i >= 0 && i <= 8))
		status = 9 - i;
	return (status);
}		

int	ft_printf(const char *string, ...)
{
	size_t			sti;
	size_t			cnt;
	unsigned int	status;
	va_list			args;

	sti = 0;
	cnt = 0;
	status = 0;
	va_start(args, string);
	while (string[sti])
	{
		status = stts_updt(status, string[sti]);
		cnt = status == 0 ? cnt + 1 : cnt + 0;
	}
	va_end(args);
	return (cnt);
}
