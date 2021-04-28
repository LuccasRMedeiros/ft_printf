/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_settype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:03:41 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/28 16:10:20 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static bool	zero_length(t_fspec *test)
{
	if (test->s == 's' && test->l >= test->sz)
		return (true);
	else if (test->s != 's' && test->l <= test->sz)
		return (true);
	return(false);
}

static void	calc_size(t_fspec **ret)
{
	t_fspec	*p_ret;

	p_ret = *ret;
	if (p_ret->s == 'c')
		p_ret->sz = 1;
	else
		p_ret->sz = ft_strlen(p_ret->dt);
	if (p_ret->fs == '0' && (!p_ret->p && p_ret->w > p_ret->sz))
		p_ret->l = p_ret->w - p_ret->sz;
	else if (p_ret->p)
	{
		if (zero_length(p_ret))
			p_ret->l = 0;
		else if (p_ret->s == 's' && p_ret->l < p_ret->sz)
			p_ret->sz = p_ret->l;
		if (p_ret->l >= p_ret->sz)
			p_ret->l -= p_ret->sz;
	}
	if (p_ret->w < p_ret->l + p_ret->sz)
		p_ret->w = p_ret->l + p_ret->sz;
}

static void	wildcard(t_fspec **ret, int arg)
{
	t_fspec *p_ret;

	p_ret = *ret;
	if (arg < 0)
	{
		p_ret->fs = '-';
		arg *= -1;
	}
	if (p_ret->p)
	{
		if (p_ret->l > 0)
			p_ret->l = 0;
		else
			p_ret->l = arg;
	}
	else
	{
		if (p_ret->w > 0)
			p_ret->w = 0;
		else
			p_ret->w = arg;
	}
}

static char	*atoi_thn_adv(t_fspec **ret, const char *str)
{
	t_fspec	*p_ret;
	size_t	sz;
	size_t	i;
	char	str_c;

	p_ret = *ret;
	sz = 0;
	i = 0;
	str_c = '\0';
	while (ft_isdigit(str[i]) && str[i])
	{
		str_c = str[i];
		sz = (sz * 10) + ft_atoi(&str_c);
		++i;
	}
	if (p_ret->p)
		p_ret->l = sz;
	else
		p_ret->w = sz;
	return ((char*)str + (i - 1));
}

t_fspec	*pf_settype(const char *str, va_list args)
{
	t_fspec *ret;
	char	str_c;

	ret = pf_newfspec();
	str_c = '\0';
	while (++str && ret->init)
	{
		str_c = *str;
		if (ft_strhvchr(P_FLAGS, str_c) && !(ret->fs == '-'))
			ret->fs = str_c;
		else if (str_c == '*')
			wildcard(&ret, va_arg(args, int));
		else if (str_c == '.')
			ret->p = true;
		else if (ft_strhvchr(P_SIZES, str_c))
			str = atoi_thn_adv(&ret, str);
		else if (ft_strhvchr(P_SPECS, str_c))
		{
			ret->init = false;
			ret->s = str_c;
		}
	}
	pf_parser(&ret, args);
	calc_size(&ret);
	return (ret);
}
