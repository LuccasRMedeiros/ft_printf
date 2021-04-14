/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_newfspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:22:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/13 19:53:18 by lrocigno         ###   ########.fr       */
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
	new->init = false;
	new->align = '\0';
	new->fill = '\0';
	new->spaces = 0;
	new->format = '\0';
	new->output = NULL;
	return (new);
}
