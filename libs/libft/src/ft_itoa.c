/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:41:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/16 22:39:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		powerten(long int n)
{
	int	nlen;
	int power;

	nlen = ft_intlen(n);
	power = 1;
	while (nlen > 1)
	{
		power *= 10;
		nlen--;
	}
	return (power);
}

char			*ft_itoa(int n)
{
	long int	ln;
	char		*itoa;
	int			i;
	int			du;

	ln = n;
	itoa = malloc(sizeof(char) * (ft_intlen(ln) + 1));
	if (!itoa)
		return (NULL);
	i = 0;
	if (ln < 0)
	{
		itoa[i++] = '-';
		ln *= -1;
	}
	du = powerten(ln);
	while (du > 0)
	{
		itoa[i++] = (ln / du) + 48;
		ln %= du;
		du /= 10;
	}
	itoa[i] = '\0';
	return (itoa);
}
