/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_settype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:03:41 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/03 16:44:15 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	wildcard(t_fspec *ret, int arg)
{
	if (ret->p)
	{
		if (ret->l > 0 || arg < 0)
		{
			ret->l = 0;
			ret->p = false;
		}
		else
			ret->l = arg;
	}
	else
	{
		if (arg < 0)
		{
			ret->fs = '-';
			arg *= -1;
		}
		if (ret->w > 0)
			ret->w = 0;
		else
			ret->w = arg;
	}
}

static char	*atoi_thn_adv(t_fspec *ret, const char *str)
{
	size_t	sz;
	size_t	i;
	char	str_c;

	sz = 0;
	i = 0;
	str_c = '\0';
	while (ft_isdigit(str[i]) && str[i])
	{
		str_c = str[i];
		sz = (sz * 10) + ft_atoi(&str_c);
		++i;
	}
	if (ret->p)
		ret->l = sz;
	else
		ret->w = sz;
	return ((char *)str + (i - 1));
}

static char	*parser(t_fspec *tp, va_list args)
{
	if (ft_strhvchr(S_NUM, tp->s))
		return (pf_numparser(tp, args));
	else if (ft_strhvchr(S_ALP, tp->s))
		return (pf_txtparser(tp, args));
	return (NULL);
}

t_fspec	*pf_settype(const char *str, va_list args)
{
	t_fspec	*ret;
	char	str_c;

	ret = pf_newfspec();
	str_c = '\0';
	while (*str && ++str && ret->init)
	{
		str_c = *str;
		if (ft_strhvchr(P_FLAGS, str_c) && !(ret->fs == '-'))
			ret->fs = str_c;
		else if (str_c == '*')
			wildcard(ret, va_arg(args, int));
		else if (str_c == '.')
			ret->p = true;
		else if (ft_strhvchr(P_SIZES, str_c))
			str = atoi_thn_adv(ret, str);
		else if (ft_strhvchr(P_SPECS, str_c))
		{
			ret->init = false;
			ret->s = str_c;
		}
	}
	pf_refine_weights(ret, args);
	ret->dt = parser(ret, args);
	return (ret);
}
