/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/13 11:52:16 by lrocigno         ###   ########.fr       */
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

static t_fspec	*type_check(t_fspec *type, const char *string)
{
	size_t	i;

	i = 1;
	type->init = true;
	if (ft_strhvchr(string[i], P_ALIGN))
	{
		type->align = string[i];
		i++;
	}
	if (ft_strhvchr(string[i], P_FILLR))
	{
		type->fill = true;
		i++;
	}
	if (ft_isdigit(string[i]) && string[i] != '0')
	{
		type->spaces = ft_atoi(string + i);
		type->spaces = type->spaces < 0 ? 0 : type->spaces;
		i += ft_intlen(type->spaces);
	}
	type->format = string[i];
	return (type);
}

int				ft_printf(const char *string, ...)
{
	size_t	sti;
	size_t	cnt;
	va_list	args;
	t_fspec	*type;

	sti = 0;
	cnt = 0;
	type = new_fspec();
	va_start(args, string);
	while (string[sti])
	{
			if (string[sti] == '%')
		{
			type = type_check(type, string + sti);
			type->output = pf_textformat(type, pf_parser(args, type));
			ft_putstr_fd(type->output, 1);
			cnt += ft_strlen(type->output);
		}
		ft_putchar_fd(string[sti], 1);
		sti++;
	}
	va_end(args);
	del_fspec(&type);
	return (cnt);
}
