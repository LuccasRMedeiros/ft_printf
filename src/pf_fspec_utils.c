/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fspec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:22:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/13 11:53:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Functions heres are for manage t_fspec types.
** new_fspec return a pointer to an initialized t_fspec. It uses malloc to     -
** allocate an address to it. That mean when a t_fspec isn't needed anymore,   -
** such address must be freed, here comes the destroy_fspec.
** destroy_fspec anullates each data contained in each part of the structure,  -
** then free the pointer and do not return.
*/

t_fspec	*new_fspec(void)
{
	t_fspec	*new

	new->= malloc(sizeof(t_fspec));
	new->init = false;
	new->align = '\0';
	new->fill = '\0';
	new->spaces = 0;
	new->format = '\0';
	new->output = NULL;
	return (new);
}

void	del_fspec(t_fspec **del)
{
	*del->init = 0;
	*del->align = 0;
	*del->fill = 0;
	*del->spaces = 0;
	*del->format = 0;
	*del->output = NULL;
	free(*del);
}
