/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_delfspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:40:58 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/13 20:12:58 by lrocigno         ###   ########.fr       */
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
	del->init = 0;
	del->align = 0;
	del->fill = 0;
	del->spaces = 0;
	del->format = 0;
	del->output = NULL;
	free(del);
}
