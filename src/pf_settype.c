/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_typeset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:03:41 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/18 12:11:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static size_t		calc_size(bool p, size_t w, size_t l, char s, char *dt)
{
	size_t ret;
	size_t dt_len;

	ret = 0;
	dt_len = ft_strlen(dt);
	if (ft_strhvchr(C_ALP, &s))
		ret = p ? l : dt_len;
	else if (ft_strhvchr(C_NUM, &s))
		ret = p && l > dt_len ? l : dt_len;
	else
		ret = w;
	ret = ret > w ? ret : w;
	return (ret);
}

static void		wildcard(t_fspec **ret, unsigned int arg)
{
	t_fspec *p_ret;

	p_ret = *ret;
	if (p_ret->p)
		p_ret->l = p_ret->l != 0 ? 0 : arg;
	else
		p_ret->w = p_ret->w != 0 ? 0 : arg;
}

static char		*atoi_thn_adv(t_fspec **ret, const char *str)
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

t_fspec			*pf_settype(const char *str, va_list args)
{
	t_fspec *ret;
	char	str_c;

	ret = pf_newfspec();
	str_c = '\0';
	while (++str && ret->init)
	{
		str_c = *str;
		if (ft_strhvchr(P_FLAGS, &str_c) && !(ft_strhvchr(ret->fs, &str_c)))
			ret->fs[ft_strlen(ret->fs)] = str_c;
		else if (str_c == '*')
			wildcard(&ret, va_arg(args, unsigned int));
		else if (str_c == '.')
			ret->p = true;
		else if (ft_strhvchr(P_SIZES, &str_c))
			str = atoi_thn_adv(&ret, str);
		else if (ft_strhvchr(P_SPECS, &str_c))
		{
			ret->init = false;
			ret->s = str_c;
		}
	}
	ret->dt = pf_parser(args, ret->s);
	ret->sz = calc_size(ret->p, ret->w, ret->l, ret->s, ret->dt);
	return (ret);
}
