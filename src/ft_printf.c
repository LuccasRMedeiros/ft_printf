/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/15 00:03:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Printf should receive indenfinite arguments and interpolate them into the   -
** received string (if necessary and in the correct format) and print it in the-
**  terminal.
** Upon a succesfull execution, printf returns the amount of printed           -
** characters
*/

#include <ft_printf.h>
#include <stdio.h>

static f_type	*set_type(char c, f_spec *type)
{
	if (ft_strhvchr(c, P_FLAGS) && !(ft_strhvchr(c, type->flags)))
		type->flags[ft_strlen(type->flags)] = c;
	if (ft_strhvchr(c, P_WIDTH) && !(type->precision))
		type->width = c == * ? c : ft_atoi(&c);
	if (c == '.')
		type->precision = true;
	if (ft_strhvchr(c, P_LNGTH))
		type->length = ft_atoi(&c);
	if (ft_strhvchr(c, P_SPECS))
	{
		type->init = false;
		type->specifier = c;
	}
	return (type);
}

int				ft_printf(const char *string, ...)
{
	size_t	cnt;
	va_list	args;
	t_fspec	*type;

	cnt = 0;
	type = pf_newfspec();
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
			type->init = true;
		if (type->init)
			type = set_type(*string, type);
		else
		{
			ft_putchar_fd(*string, 1);
			++cnt;
		}
		*++string;
	}
	va_end(args);
	pf_delfspec(&type);
	return (cnt);
}
