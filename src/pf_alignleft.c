/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_alignleft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:08:21 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/18 17:14:54 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*pf_alignleft(size_t sz, size_t ln, char f, char *dt)
{
	size_t	ds;
	char	*ret;

	ds = ft_strlen(dt);
	ret = malloc(sizeof *ret * sz);
	if(!ret)
		return (NULL);
	ret[sz] = '\0';
	while (sz > 0)
	{
		if (sz > ln)
			ret[--sz] = ' ';
		else if (sz == ln)
		{
			while (ds > 0)
				ret[--sz] = dt[--ds];
			ln = sz;
			while (ln > 0)
			{
				ret[--sz] = f;
				--ln;
			}
		}
	}
	return (ret);
}
