/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhvchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:29:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/10 20:41:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Receives a char and a string and search for the char into the string. If    -
** find it, returns true, otherwise, false.
*/

#include <libft.h>

bool	ft_strhvchr(char c, const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == c)
			return (true);
		i++;
	}
	return (false);
}
