/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:50:41 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/04 01:14:14 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parser checks the character that is being printed and tell to pritnf how to -
** deal with it.
** To do so, ft_printf_parser changes the value contained into status address  -
** and returns a pointer to a proper function to deal with the case.
** The possible values for "status" are in a range from 0 to 8. 0 tells printf -
** to print the character it is looking to, 1 works as an alert to parser,     -
** 1 is a value that is only possible when the character is '%', that means the-
**  next character will be a format specifier, and this make possible to printf-
**  decide which "ft_put" function family is more adequate to deal with the    -
** value to be interpolated.
*/

#include <libft.h>

static ft_put	parser_select(int i)
{
	ft_put ret;

	ret = NULL;
	if (i == 1)
		ret = &ft_putstr_fd;
	else if (i == 2)
		ret = &ft_putstr_fd;
	else if (i == 3)
		ret = &ft_putnbr_fd;
	else if (i == 4)
		ret = &ft_putnbr_fd;
	else if (i == 5)
		ret = &ft_putnbr_fd;
	else if (i == 6)
		ret = &ft_putstr_fd;
	else if (i == 7)
		ret = &ft_putstr_fd;
	else
		ret = &ft_putchar_fd;
	return (ret);
}

ft_put			ft_printf_parser(const char c, unsigned int *status)
{
	size_t		i;
	ft_put		pf;

	i = 0;
	pf = NULL;
	while (c != P_CONVS[i] && P_CONVS[i])
		i++;
	if (i > 8)
		status = 0;
	else if (!status && i == 8)
		status = 1;
	else if (status == 1 && (i >= 0 && i <= 8))
	{
		status = 9 - i;
		pf = parser_select(i);
	}
	return (pf);
}
