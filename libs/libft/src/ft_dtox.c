/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 09:29:11 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/09 17:43:35 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_dtox takes an int as argument, converts it to hexadecimal base and return-
**  a pointer to char containing the value formated as string.
** It allocate memory like ft_itoa, so free is required to be used along with  -
** this function.
*/

#include <libft.h>

static size_t	hex_len(unsigned int dn)
{
	size_t	len;

	len = 0;
	while (dn)
	{
		len++;
		dn /= 16;
	}
	return (len);
}

char	*ft_dtox(unsigned int dn)
{
	size_t	len;
	char	dgt;
	char	*hex;

	len = hex_len(dn);
	hex = malloc(sizeof(char) * len);
	if (!hex)
		return (NULL);
	hex[len] = 0;
	while (len--)
	{
		dgt = dn % 16;
		if (dgt > 9 && dgt < 16)
			dgt = dgt + 55;
		else
			dgt += 48;
		hex[len] = dgt;
		dn /= 16;
	}
	return (hex);
}
