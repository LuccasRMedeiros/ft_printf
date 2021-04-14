/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:50:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/14 18:19:24 by lrocigno         ###   ########.fr       */
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

static int		status(char c)
{
	if (ft_strhvchr(c, P_FLAGS))
		return (0);
	else if (ft_strhvchr(c, P_WIDTH))
		return (1);
	else if (ft_strhvchr(c, P_PRESC))
		return (2);
	else if (ft_strhvchr(c, P_LNGTH))
		return (3);
	else if (ft_strhvchr(c, P_SPECS))
		return (4);
	return (-1);

static size_t	type_check(t_fspec **type, const char *string)
{
	int		status;
	size_t	i;
	t_fspec	*aux;

	status = 0;
	i = 0;
	aux = *type;
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
