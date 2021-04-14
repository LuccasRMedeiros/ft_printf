/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/13 22:17:54 by lrocigno         ###   ########.fr       */
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

static size_t	type_check(t_fspec **type, const char *string)
{
	size_t	i;
	t_fspec	*aux;

	i = 1;
	aux = *type;
	aux->init = true;
	if (ft_strhvchr(string[i], P_ALIGN))
	{
		aux->align = string[i];
		i++;
	}
	if (ft_strhvchr(string[i], P_FILLR))
	{
		aux->fill = true;
		i++;
	}
	if (ft_isdigit(string[i]) && string[i] != '0')
	{
		aux->spaces = ft_atoi(string + i);
		aux->spaces = aux->spaces < 0 ? 0 : aux->spaces;
		i += ft_intlen(aux->spaces);
	}
	aux->format = string[i];
	return (i);
}

int				ft_printf(const char *string, ...)
{
	size_t	sti;
	size_t	cnt;
	va_list	args;
	t_fspec	*type;

	sti = 0;
	cnt = 0;
	type = pf_newfspec();
	va_start(args, string);
	while (string[sti])
	{
		if (string[sti] == '%')
		{
			sti += type_check(&type, string + sti) + 1;
			type->output = pf_textformat(type, pf_parser(args, type));
			ft_putstr_fd(type->output, 1);
			cnt += ft_strlen(type->output);
		}
		ft_putchar_fd(string[sti], 1);
		cnt++;
		sti++;
	}
	va_end(args);
	pf_delfspec(&type);
	return (cnt);
}
