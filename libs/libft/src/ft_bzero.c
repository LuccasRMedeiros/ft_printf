/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 09:47:10 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 18:57:34 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_aux;
	size_t			i;

	s_aux = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		s_aux[i] = 0;
		i++;
	}
}
