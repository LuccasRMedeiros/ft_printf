/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_txtparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:57:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/03 17:59:34 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pf_txtparser receives the va_list with arguments passed and the type which 
** is  -
** been printed, so it is able to choose what of its subfunctions fit better   -
** to convert such type into a string.
** *int_parser have a pointer to function parameter because it can work with   -
** both ft_itoa (to create a string that represents the number in decimal base)-
**  and ft_dtox (to create a string that represents the number in hexdecimal   -
** base).
** Note that there's no function to convert a string to another string cause   -
** obviously redudant.
*/

#include <ft_printf.h>

static char	*percent_parser(t_fspec *tp)
{
	size_t	i;
	size_t	wd;
	char	*ret;

	i = 0;
	wd = tp->w;
	ret = ft_calloc(tp->sz + 1, sizeof(char));
	if (!ret)
		return (NULL);
	while (tp->fs == '0' && --wd)
	{
		ret[i] = '0';
		++i;
	}
	ret[i] = '%';
	return (ret);
}

static char	*char_parser(char arg, t_fspec *tp)
{
	char	*ret;

	ret = malloc(sizeof(char) + 1);
	if (!ret)
		return (NULL);
	if (!tp->w)
		tp->w = 1;
	ret[0] = arg;
	ret[1] = '\0';
	return (ret);
}

static char	*pointer_parser(va_list args, t_fspec *tp)
{
	char	*hex;
	char	*ret;

	ret = ft_strdup("0x");
	if (!ret)
		return (NULL);
	if (tp->fs == '0' && tp->l > tp->sz)
	{
		tp->l -= 2;
		tp->sz -= 2;
	}
	tp->sz += 2;
	if (tp->w < tp->sz)
		tp->w = tp->sz;
	hex = pf_numparser(tp, args);
	ret = ft_reallocncat(ret, hex);
	free(hex);
	if (!ret)
		return (NULL);
	return (ret);
}

static char	*string_parser(char *str, t_fspec *tp)
{
	char	*ret;
	char	*str_copy;
	char	*str_null;
	size_t	i;

	ret	= ft_calloc(tp->w + 1, sizeof(char));
	str_copy = malloc((tp->sz + 1) * sizeof(char));
	ft_strlcpy(str_copy, str, tp->sz + 1);
	str_null = ft_strdup("(null)");
	if (!str)
		str = str_null;
	i = 0;
	if (tp->fs == '0' && !tp->p)
	{
		while (i < tp->w - tp->sz)
		{
			ret[i] = '0';
			++i;
		}
		tp->sz = tp->w;
	}
	ret = ft_reallocncat(ret, str);
	free(str_copy);
	free(str_null);
	return (ret);
}

char	*pf_txtparser(t_fspec *tp, va_list args)
{
	if (tp->s == 'c')
		return (char_parser(va_arg(args, int), tp));
	else if (tp->s == 's')
		return (string_parser(va_arg(args, char *), tp));
	else if (tp->s == 'p')
		return (pointer_parser(args, tp));
	else if (tp->s == '%')
		return (percent_parser(tp));
	return (NULL);
}
