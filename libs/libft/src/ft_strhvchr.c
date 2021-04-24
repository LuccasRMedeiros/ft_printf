/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhvchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocignoS <lrocigno@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:29:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/24 10:34:50 by lrocignoS        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Receives a pair of strings and search for a similar char between them.
*/

#include <libft.h>

bool	ft_strhvchr(const char *string, unsigned char c)
{
	while (*string)
	{
		if (*string == c)
			return (true);
		++string;
	}
	return (false);
}
