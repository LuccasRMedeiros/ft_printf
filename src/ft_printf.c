/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/06 14:07:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Printf should receive indenfinite arguments and interpolate them into the   -
** received string (if necessary and in the correct format) and print it in the-
**  terminal.
** Upon a succesfull execution, printf returns the amount of printed          -
** characters
*/

#include <libft.h>
#include <stdio.h>

static int	*int_parser(va_list args)
{
	int	holder;
	int	*address;

	holder = va_arg(args, int);
	address = &holder;
	return (address);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	size_t	cnt;
	int		stt;
	int		*status;
	ft_put	func;

	cnt = 0;
	stt = 0;
	status = &stt;
	va_start(args, string);
	while (string[cnt])
	{
		func = ft_func_sel(string[cnt], status);
		if (*status == 0)
			ft_putchar_fd(string[cnt], 1);
		else if (*status >= 2 && *status <= 4)
		{
			func(int_parser(args), 1);
		}
		cnt++;
	}
	va_end(args);
	return (cnt);
}
