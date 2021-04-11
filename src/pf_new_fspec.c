/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fspec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:22:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/11 00:06:47 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function is use to create and initialize a t_fspec structure pointer.
** The pointer address is given by malloc, so every call must have a free when -
** such pointer don't be necessary anymore.
*/

t_fspec	*new_fspec(void)
{
	t_fspec	*new;

	new = malloc(sizeof(t_fspec));
	new->init = false;
	new->align = '\0';
	new->fill = false;
	new->space = 0;
	new->format = '\0';
	new->output = NULL;
	return (new);
}

void	destroy_fspec(t_fspec *del)
{
	del->init = 0;
	del->align = 0;
	del->fill = 0;
	del->space = 0;
	del->format = 0;
	del->output = NULL;
	free(del);
}
