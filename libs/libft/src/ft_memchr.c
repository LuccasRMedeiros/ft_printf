/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 19:19:20 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 19:18:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str_aux;
	unsigned char	c_aux;
	size_t			i;

	str_aux = (unsigned char*)str;
	c_aux = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str_aux[i] == c_aux)
		{
			return ((void*)str + i);
		}
		i++;
	}
	return (NULL);
}
