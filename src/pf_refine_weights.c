/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_refine_weights.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:27:52 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/01 22:56:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void refwghts_percent(t_fspec *tp)
{
	tp->sz = 1;
	if (!tp->w)
		tp->w = 1;
	else if (tp->fs == '0' && tp->w > 0)
		tp->sz = tp->w;
}

static void refwghts_string(char *arg, t_fspec *tp)
{
	tp->sz = ft_strlen(arg);
	if (!arg)
		tp->sz = 6;
	if (tp->l > tp->sz)
		tp->l = 0;
	else if (tp->p && tp->l < tp->sz)
		tp->sz = tp->l;
	if (tp->w < tp->sz)
		tp->w = tp->sz;
}

static void	refwghts_unsdec(unsigned int arg, t_fspec *tp)
{
	if (tp->s == 'u')
		tp->sz = ft_uintlen(arg);
	else if (tp->s == 'x' || tp->s == 'X')
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

static void	refwghts_dec(int arg, t_fspec *tp)
{
	tp->sz = ft_intlen(arg);
	if (arg < 0)
		tp->sig = '-';
	if (tp->fs == '0' && !tp->p && tp->w > tp->sz)
	{
		tp->l = tp->w - tp->sz;
		if (tp->sig)
			--tp->l;
	}
	else if (tp->p && tp->l > tp->sz)
		tp->l -= tp->sz;
	else if (tp->p && (!tp->l && !arg))
		tp->sz = 0;
	else if (tp->p && tp->l <= tp->sz)
		tp->l = 0;
	if (tp->sig)
		++tp->sz;
	tp->sz += tp->l;
	if (tp->w < tp->sz)
		tp->w = tp->sz;
}

void	pf_refine_weights(t_fspec *tp, va_list args)
{
	va_list c_args;

	va_copy(c_args, args);
	if (tp->s == 'd' || tp->s == 'i')
		refwghts_dec(va_arg(c_args, int), tp);
	else if (tp->s == 'u' || tp->s == 'x' || tp->s == 'X')
		refwghts_unsdec(va_arg(c_args, unsigned int), tp);
	else if (tp->s == 's')
		refwghts_string(va_arg(c_args, char *), tp);
	else if (tp->s == 'c')
		tp->sz = 1;
	else if (tp->s == '%')
		refwghts_percent(tp);
	va_end(c_args);
}
