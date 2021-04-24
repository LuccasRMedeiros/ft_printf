/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:04:30 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 19:07:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*holder;

	if (*lst == NULL)
		return ;
	aux = *lst;
	while (aux != NULL)
	{
		del(aux->content);
		holder = aux->next;
		free(aux);
		aux = holder;
	}
	*lst = NULL;
}
