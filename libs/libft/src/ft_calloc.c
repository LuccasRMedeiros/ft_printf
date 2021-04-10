/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:21:59 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 18:57:47 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t n_itens, size_t size)
{
	void	*temp;

	temp = malloc(n_itens * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, n_itens * size);
	return (temp);
}
