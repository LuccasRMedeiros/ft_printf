/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:57:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/12 22:24:07 by lrocigno         ###   ########.fr       */
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

static char *char_parser(char arg, t_fspec *type)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char*) * type->spaces);
	if (!ret)
		return (NULL);
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

void		pf_parser(va_list args, t_fspec *type)
{
	if (type->format == 'c')
		type->output = char_parser(va_arg(args, int));
	else if (type->format == 'd' || type->format == 'i')
		type->output = ft_itoa(va_arg(args, int));
	else if (type->format == 's')
		type->output = ft_strdup(va_arg(args, char*));
	else if (type->format == 'u')
		type->output = ft_utoa(va_arg(args, unsigned int));
	else if (type->format == 'p')
		type->output = pointer_parser(va_arg(args, unsigned long int));
	else if (type->format == 'x')
		type->output = ft_dtox(va_arg(args, unsigned int), true);
	else if (type->format == 'X')
		type->output = ft_dtox(va_arg(args, unsigned int), false);
}
