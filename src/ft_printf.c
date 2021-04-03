/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/03 15:47:16 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Printf should receive indenfinite arguments and interpolate them into the   -
** received string (if necessary and in the correct format) and print it in the-
**  terminal.
** Upon a succesfully execution, printf returns the amount of printed          -
** characters
*/

#include <libft.h>

int	ft_printf(const char *string, ...)
{
	va_list	args;
	size_t	cnt;
	int		parser;
	int		test;

	cnt = 0;
	va_start(args, string);
	test = va_arg(args, int);
	while (string[cnt])
	{
		parser = ft_printf_parser(string[cnt]);
		if (parser == 0)
			ft_putchar_fd(string[cnt], 1);
		else if (parser == 5)
			ft_putnbr_fd(test, 1);
		cnt++;
	}
	va_end(args);
	return (cnt);
}
