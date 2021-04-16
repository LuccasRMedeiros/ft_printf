/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_delfspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:40:58 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/15 22:28:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** del_fspec anullates each data contained in each part of the structure, then -
** free the pointer and do not return.
*/

#include <ft_printf.h>

void	pf_delfspec(t_fspec **fspec)
{
	t_fspec *del;

	del = *fspec;
	del->init = false;
	del->fs = NULL;
	del->w = 0;
	del->p = false;
	del->l = 0;
	del->s = '\0';
	del->dt = NULL;
	del->sz = 0;
	free(del);
}
