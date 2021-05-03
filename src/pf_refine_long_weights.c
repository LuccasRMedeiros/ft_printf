/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_refine_long_weights.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:27:52 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/03 12:58:26 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	refwghts_lunsdec(long unsigned int arg, t_fspec *tp)
{
	if (tp->s == 'p')
		tp->sz = ft_hexlen(arg);
	if (tp->fs == '0' && !tp->p && tp->w > tp->sz)
		tp->l = tp->w - tp->sz;
	else if (tp->p && tp->l > tp->sz)
		tp->l -= tp->sz;
	else if (tp->p && (!tp->l && !arg))
		tp->sz = 0;
	else if (tp->p && tp->l <= tp->sz)
		tp->l = 0;
	tp->sz += tp->l;
	if (tp->w < tp->sz)
		tp->w = tp->sz;
}

void	pf_refine_long_weights(t_fspec *tp, va_list args)
{
	va_list	c_args;

	va_copy(c_args, args);
	if (tp->s == 'p')
		refwghts_lunsdec(va_arg(c_args, long unsigned int), tp);
	va_end(c_args);
}
