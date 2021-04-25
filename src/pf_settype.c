/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_settype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocignoS <lrocigno@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:03:41 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/25 10:42:59 by lrocignoS        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	calc_size(t_fspec **ret)
{
	t_fspec	*p_ret;

	p_ret = *ret;
	p_ret->sz = ft_strlen(p_ret->dt);
	if (p_ret->fs == '0' && (!p_ret->p && p_ret->w > p_ret->sz))
		p_ret->l = p_ret->w - p_ret->sz;
	else if ((p_ret->p || p_ret->fs == '-') && ft_strhvchr(C_ALP, p_ret->s))
	{
		if (p_ret->l < p_ret->sz)
			p_ret->sz = p_ret->l;
		else
			p_ret->l = 0;
	}
	else if (p_ret->p)
	{
		if (p_ret->l < p_ret->sz)
			p_ret->l = p_ret->sz;
	}
	if (p_ret->l > p_ret->sz)
		p_ret->l -= p_ret->sz;
	else
		p_ret->l = 0;
	if (p_ret->w < p_ret->l + p_ret->sz)
		p_ret->w = p_ret->l + p_ret->sz;
}

static void	wildcard(t_fspec **ret, unsigned int arg)
{
	t_fspec *p_ret;

	p_ret = *ret;
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
			wildcard(&ret, va_arg(args, unsigned int));
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
