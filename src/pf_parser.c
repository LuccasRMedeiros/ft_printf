/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:57:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/09 18:17:34 by lrocigno         ###   ########.fr       */
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

static char *char_parser(char arg)
{
	char *ret;

	ret = malloc(sizeof(char*));
	if (!ret)
		return (NULL);
	ret[0] = arg;
	ret[1] = '\0';
	return (ret);
}

static char *pointer_parser(long int arg)
{
	char *hex;
	char *ret;

	hex = ft_ltox(arg, true);
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
	return (ret);
}

char		*pf_parser(va_list args, unsigned int type)
{
	char	*ret;

	ret = NULL;
	if (type == 2)
		ret = char_parser(va_arg(args, int));
	else if (type == 3 || type == 4)
		ret = ft_itoa(va_arg(args, int));
	else if (type == 5)
		ret = ft_strdup(va_arg(args, char*));
	else if (type == 6)
		ret = ft_utoa(va_arg(args, unsigned int));
	else if (type == 7)
		ret = pointer_parser(va_arg(args, unsigned long int));
	else if (type == 8)
		ret = ft_dtox(va_arg(args, unsigned int), true);
	else if (type == 9)
		ret = ft_dtox(va_arg(args, unsigned int), false);
	return (ret);
}
