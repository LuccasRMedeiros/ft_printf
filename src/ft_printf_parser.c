/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:50:41 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/02 10:56:56 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Parser checks the actual character that is being printed and tell to pritnf -
** how to deal with it
*/

#include <libft.h>

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

	i = 0;
	while (c != P_CONVS[i] && P_CONVS[i])
		i++;
	if (status == 1 && ft_printf_parser_select(i) == 1)
		status = 0;
	else
		status = ft_printf_parser_select(i);
	return (status);
}
