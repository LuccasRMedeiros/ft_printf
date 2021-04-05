/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/05 19:34:06 by lrocigno         ###   ########.fr       */
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

int	ft_printf(const char *string, ...)
{
	va_list			args;
	size_t			cnt;
	unsigned int	status;
	int				data;
	ft_put			func;

	cnt = 0;
	status = 0;
	va_start(args, string);
	data = va_arg(args, int);
	while (string[cnt])
	{
		func = ft_func_sel(string[cnt], &status);
		if (!status)
			ft_putchar_fd(string[cnt], 1);
		else if (status >= 2 && status <= 3)
			func(&data, 1);
		cnt++;
	}
	va_end(args);
	return (cnt);
}
