/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:04:44 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 19:14:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ret;
	t_list *temp;

	ret = NULL;
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			if (!ret)
				return (NULL);
			ft_lstclear(&ret, del);
		}
		lst = lst->next;
		ft_lstadd_back(&ret, temp);
	}
	return (ret);
}
