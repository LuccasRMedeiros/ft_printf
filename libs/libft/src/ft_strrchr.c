/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:46:59 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 19:31:20 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	*str_aux;
	unsigned char	find;
	int				i;

	str_aux = (unsigned char*)str;
	find = (unsigned char)c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == find)
		{
			return ((char*)str + i);
		}
		i--;
	}
	return (NULL);
}
