/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:38:37 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/02 12:24:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	hex_parser(long unsigned int arg, int font, t_fspec *tp, char *ret)
{
	size_t	i;
	char	*dtox;

	i = 0;
	while (tp->l)
	{
		ret[i] = '0';
		--tp->l;
		++i;
	}
	dtox = ft_dtox(arg, font);
	ft_strlcat(ret, dtox, tp->sz + 1);
	free(dtox);
}

static void	undec_parser(unsigned int arg, t_fspec *tp, char *ret)
{
	size_t	i;
	char	*utoa;

	i = 0;
	while (tp->l)
	{
		ret[i] = '0';
		--tp->l;
		++i;
	}
	utoa = ft_utoa(arg);
	ft_strlcat(ret, utoa, tp->sz + 1);
	free(utoa);
}

static void	dec_parser(int arg, t_fspec *tp, char *ret)
{
	size_t	i;
	char	*itoa;

	i = 0;
	if (tp->sig)
	{
		ret[i] = tp->sig;
		++i;
	}
	while (tp->l)
	{
		ret[i] = '0';
		--tp->l;
		++i;
	}
	itoa = ft_itoa(arg);
	if (arg < 0)
		ft_strlcat(ret, itoa + 1, tp->sz + 1);
	else
		ft_strlcat(ret, itoa, tp->sz + 1);
	free(itoa);
}

char	*pf_numparser(t_fspec *tp, va_list args)
{
	char	*ret;

	ret = ft_calloc(tp->sz + 1, sizeof *ret);
	if (!ret)
		return (NULL);
	if (tp->s == 'd' || tp->s == 'i')
		dec_parser(va_arg(args, int), tp, ret);
	else if (tp->s == 'u')
		undec_parser(va_arg(args, unsigned int), tp, ret);
	else if (tp->s == 'x' || tp->s == 'p')
		hex_parser(va_arg(args, long unsigned int), LOW, tp, ret);
	else if (tp->s == 'X')
		hex_parser(va_arg(args, long unsigned int), UPR, tp, ret);
	return (ret);
}
