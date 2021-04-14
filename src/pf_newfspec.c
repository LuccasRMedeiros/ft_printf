/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_newfspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:22:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/14 10:35:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** new_fspec return a pointer to an initialized t_fspec. It uses malloc to     -
** allocate an address to it. That mean when a t_fspec isn't needed anymore,   -
** such address must be freed.
*/

#include <ft_printf.h>

t_fspec	*pf_newfspec(void)
{
	t_fspec	*new;

	new = malloc(sizeof(t_fspec));
	if (!new)
		return (NULL);
	new->align = '\0';
	new->fill = NULL;
	new->spaces = 0;
	new->precision = false;
	new->format = '\0';
	new->output = NULL;
	return (new);
}
