/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/14 11:41:16 by lrocigno         ###   ########.fr       */
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

static int		flagid(char c)
{
	if (ft_strhvchr(c, P_CONVS))
		return (1);
	else if (ft_strhvchr(c, P_ALIGN))
		return (2);
	else if (ft_strhvchr(c, P_FILLR))
		return (3);
	else if (c == '.')
		return (4);
	return (0);
}

static size_t	type_check(t_fspec **type, const char *string)
{
	size_t	i;
	size_t	fillers;
	t_fspec	*aux;

	i = 0;
	fillers = 0;
	aux = *type;
	while (!aux->format)
	{
		if (flagid(string[i]) == 1)
			aux->format = string[i];
		else if (flagid(string[i]) == 2 && (!aux->fill && !aux->align))
			aux->align = string[i];
		else if (flagid(string[i]) == 3 && (!aux->precision))
			aux->filler[fillers++] = string[i];
		else if (flagid(string[i]) == 4 && (!aux->precision))
			aux->precision = true;
		else

			
	}
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
			sti += type_check(&type, string + sti + 1) + 1;
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
