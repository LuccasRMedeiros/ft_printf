/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:48:04 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 19:27:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ds;
	size_t	ss;
	size_t	i;

	ds = ft_strlen(dst);
	ss = ft_strlen(src);
	i = 0;
	if (dstsize <= ds)
		return (ss + dstsize);
	while (src[i] != '\0' && (ds + i) < dstsize - 1)
	{
		dst[ds + i] = src[i];
		i++;
	}
	dst[ds + i] = '\0';
	return (ds + ss);
}
