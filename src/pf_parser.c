/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:57:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/28 12:38:27 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pf_parser receives the va_list with arguments passed and the type which is  -
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

static char	*char_parser(char arg)
{
	char	*ret;

	ret = malloc(sizeof(char) + 1);
	if (!ret)
		return (NULL);
	ret[0] = arg;
	ret[1] = '\0';
	return (ret);
}

static char	*pointer_parser(long int arg)
{
	char	*hex;
	char	*ret;
	size_t	i;

	hex = ft_ltox(arg);
	if (!hex)
		return (NULL);
	ret = ft_strdup("0x");
	i = 0;
	if (!ret)
	{
		free(hex);
		return (NULL);
	}
	ret = ft_reallocncat(ret, hex);
	while (ret[i])
	{
		ret[i] = ft_tolower(ret[i]);
		++i;
	}
	free(hex);
	if (!ret)
		return (NULL);
	return (ret);
}

static char	*lower_hxd(unsigned int dec)
{
	char	*ret;
	size_t	i;

	ret = ft_dtox(dec);
	i = 0;
	while (ret[i])
	{
		ret[i] = ft_tolower(ret[i]);
		++i;
	}
	return (ret);
}

void	pf_parser(t_fspec **tp, va_list args)
{
	t_fspec	*p_tp;
	char	*pars;

	p_tp = *tp;
	pars = NULL;
	if (p_tp->s == 'c')
		pars = char_parser(va_arg(args, int));
	else if (p_tp->s == 'd' || p_tp->s == 'i')
		pars = ft_itoa(va_arg(args, int));
	else if (p_tp->s == 's')
		pars = ft_strdup(va_arg(args, char *));
	else if (p_tp->s == 'u')
		pars = ft_utoa(va_arg(args, unsigned int));
	else if (p_tp->s == 'p')
		pars = pointer_parser(va_arg(args, unsigned long int));
	else if (p_tp->s == 'x')
		pars = lower_hxd(va_arg(args, unsigned int));
	else if (p_tp->s == 'X')
		pars = ft_dtox(va_arg(args, unsigned int));
	else if (p_tp->s == '%')
		pars = char_parser(p_tp->s);
	p_tp->dt = pars;
}
