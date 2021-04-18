/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_alignright.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:15:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/18 17:19:00 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*pf_alignright(size_t sz, size_t ln, char f, char *dt)
{
	size_t	ds;
	char	*ret;

	ds = ft_strlen(dt);
	ret = malloc(sizeof *ret * sz);
	if (!ret)
		return (NULL);
	ret[sz] = '\0';
	while (sz > 0)
	{
		ln = sz - ds;
		if (ds > 0)
			ret[--sz] = dt[--ds];
		else if (ds == 0)
		{
			while (ln > 0)
			{
				ret[--sz] = f;
				--ln;
			}
			while (sz > 0)
				ret[--sz] = ' ';
		}
	}
	return (ret);
}
