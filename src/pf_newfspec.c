/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_newfspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:22:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/14 23:30:57 by lrocigno         ###   ########.fr       */
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

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->init = false;
	new->flags = NULL;
	new->width = 0;
	new->precision = false;
	new->length = 0;
	new->specifier = '\0';
	new->size = 0;
	return (new);
}
