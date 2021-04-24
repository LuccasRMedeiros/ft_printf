/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:10:51 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/05 15:19:29 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t cnt)
{
	unsigned char	*dst_aux;
	unsigned char	*src_aux;
	unsigned char	f_char;
	size_t			i;

	if ((!dst && !src) || cnt == 0)
		return (NULL);
	dst_aux = (unsigned char *)dst;
	src_aux = (unsigned char *)src;
	f_char = (unsigned char)c;
	i = 0;
	while (i < cnt)
	{
		dst_aux[i] = src_aux[i];
		if (dst_aux[i] == f_char)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
