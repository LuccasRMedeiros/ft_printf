/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_delfspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:40:58 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/01 11:26:51 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** del_fspec anullates each data contained in each part of the structure, then -
** free the pointer and do not return.
*/

#include <ft_printf.h>

void	pf_delfspec(t_fspec **fspec)
{
	t_fspec	*del;
	char	*dt;

	del = *fspec;
	dt = del->dt;
	free(dt);
	del->init = false;
	del->fs = '\0';
	del->w = 0;
	del->p = false;
	del->l = 0;
	del->s = '\0';
	del->dt = NULL;
	del->sig = '\0';
	del->sz = 0;
	free(del);
}
