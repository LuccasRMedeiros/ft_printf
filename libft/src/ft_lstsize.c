/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:54:53 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 19:16:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	if (!lst)
		return (cnt);
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}
