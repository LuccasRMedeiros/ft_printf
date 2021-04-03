/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:50:41 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/03 15:47:15 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parser checks the character that is being printed and tell to pritnf how to -
** deal with it
*/

#include <libft.h>
#include <stdio.h>

static int	ft_printf_parser_select(int i)
{
	if (i == 9)
		return (0);
	else if (i == 8)
		return (1);
	else if (i >= 0 && i <= 7)
		return (i + 2);
	return (-1);
}

int			ft_printf_parser(const char c)
{
	size_t		i;
	static int	status;
	int			sel;

	i = 0;
	while (c != P_CONVS[i] && P_CONVS[i])
		i++;
	sel = ft_printf_parser_select(i);
	if ((status == 1 && sel == 1) || (status == 0 && sel != 1))
		status = 0;
	else if ((status == 0 && sel == 1) || status == 1)
		status = sel;
	else if (status > 1 && status <= 9)
		status = 0;
	return (status);
}
