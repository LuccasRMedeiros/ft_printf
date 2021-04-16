/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_typeset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:03:41 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/16 17:07:58 by lrocigno         ###   ########.fr       */
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

static int		atoi_thn_adv(t_fspec **ret, char *str)
{
	t_fspec *p_ret;
	size_t	sz;
	int		i;

	p_ret = *ret;
	sz = 0;
	i = 0;
	while (ft_isdigit(str[i]) && str[i])
	{
		sz = (sz * 10) + ft_atoi(&str[i]);
		++i;
	}
	if (p_ret->p)
		p_ret->l = sz;
	else
		p_ret->w = sz;
	return (i);
}

t_fspec			*pf_settype(const char *str, va_list args)
{
	t_fspec *ret;
	char	*s_aux;

	ret = pf_newfspec();
	s_aux = (char*)str;
	while (*s_aux)
	{
		if (ft_strhvchr(P_FLAGS, &*s_aux) && !(ft_strhvchr(ret->fs, &*s_aux)))
			ret->fs[ft_strlen(ret->fs)] = *s_aux;
		else if (*s_aux == '*')
			wildcard(&ret, va_arg(args, unsigned int));
		else if (*s_aux == '.')
			ret->p = true;
		else if (ft_strhvchr(P_SIZES, &*s_aux))
			s_aux += atoi_thn_adv(&ret, s_aux);
		else if (ft_strhvchr(P_SPECS, &*s_aux))
		{
			ret->init = false;
			ret->s = *str;
		}
		++s_aux;
	}
	ret->dt = pf_parser(args, ret->s);
	ret->sz = calc_size(ret->p, ret->w, ret->l, ret->s, ret->dt);
	return (ret);
}
