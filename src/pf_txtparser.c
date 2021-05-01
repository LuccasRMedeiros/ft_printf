/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_txtparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:57:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/01 18:18:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pf_txtparser receives the va_list with arguments passed and the type which is  -
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

static char	*char_parser(char arg, t_fspec *tp)
{
	char	*ret;

	ret = malloc(sizeof(char) + 1);
	if (!ret)
		return (NULL);
	tp->sz = 1;
	if (!tp->w)
		tp->w = 1;
	ret[0] = arg;
	ret[1] = '\0';
	return (ret);
}

static char	*pointer_parser(long unsigned int arg, t_fspec *tp)
{
	char	*hex;
	char	*ret;

	hex = ft_ltox(arg, LOW);
	if (!hex)
		return (NULL);
	ret = ft_strdup("0x");
	if (!ret)
	{
		free(hex);
		return (NULL);
	}
	ret = ft_reallocncat(ret, hex);
	free(hex);
	if (!ret)
		return (NULL);
	tp->sz = ft_strlen(ret);
	if (tp->w < tp->sz)
		tp->w = tp->sz;
	return (ret);
}

static char	*string_parser(char *str, t_fspec *tp)
{
	char	*ret;
	char	*str_null;

	str_null = NULL;
	ret = malloc((tp->sz + 1) * sizeof *ret);
	if (!ret)
		return (NULL);
	if (!str)
	{
		str_null = ft_strdup("(null)");
		if (!str_null)
			return (NULL);
		ft_strlcpy(ret, str_null, tp->sz + 1);
		free(str_null);
		return (ret);

	}
	ft_strlcpy(ret, str, tp->sz + 1);
	return (ret);
}

char	*pf_txtparser(t_fspec *tp, va_list args)
{
	if (tp->s == 'c')
		return (char_parser(va_arg(args, int), tp));
	else if (tp->s == 's')
		return (string_parser(va_arg(args, char *), tp));
	else if (tp->s == 'p')
		return (pointer_parser(va_arg(args, long unsigned int), tp));
	else if (tp->s == '%')
		return (char_parser('%', tp));
	return (NULL);
}
