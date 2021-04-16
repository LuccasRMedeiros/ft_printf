/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhvchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:29:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/16 18:40:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Receives a char and a string and search for the char into the string. If    -
** find it, returns true, otherwise, false.
*/

#include <libft.h>

bool	ft_strhvchr(const char *string, const char *grp_c)
{
	size_t	i;
	size_t	grp_c_sz;
	size_t	c;

	i = 0;
	grp_c_sz = ft_strlen(grp_c);
	c = grp_c_sz;
	while (string[i])
	{
		while (c > 0)
			if (grp_c[--c] == string[i])
				return (true);
		++i;
		c = grp_c_sz;
	}
	return (false);
}
