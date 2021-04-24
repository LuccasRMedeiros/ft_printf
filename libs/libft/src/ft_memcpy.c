/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:42:47 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 19:18:26 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t cnt)
{
	unsigned char	*dst_aux;
	unsigned char	*src_aux;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dst_aux = (unsigned char *)dst;
	src_aux = (unsigned char *)src;
	i = 0;
	while (i < cnt)
	{
		dst_aux[i] = src_aux[i];
		i++;
	}
	return (dst);
}
