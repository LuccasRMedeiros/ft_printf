/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:41:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/16 23:37:25 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	uintlen(unsigned int n)
{
	size_t len;

	len = 0;
	while (n)
	{
		len ++;
		n /= 10;
	}
	return (len);
}

static int		powerten(size_t nlen)
{
	int power;

	power = 1;
	while (nlen > 1)
	{
		power *= 10;
		nlen--;
	}
	return (power);
}

char			*ft_utoa(unsigned int n)
{
	unsigned long int	ln;
	size_t				nlen;
	char				*utoa;
	int					i;
	int					du;

	ln = n;
	nlen = uintlen(ln);
	utoa = malloc(sizeof(char) * (nlen + 1));
	if (!utoa)
		return (NULL);
	i = 0;
	du = powerten(nlen);
	while (du > 0)
	{
		utoa[i++] = (ln / du) + 48;
		ln %= du;
		du /= 10;
	}
	utoa[i] = '\0';
	return (utoa);
}
