/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:41:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/09 18:24:47 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_lintlen(long int n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		len ++;
		n /= 10;
	}
	return (len);
}

static int	powerten(long long int n)
{
	int	nlen;
	int	power;

	nlen = ft_lintlen(n);
	power = 1;
	while (nlen > 1)
	{
		power *= 10;
		nlen--;
	}
	return (power);
}

char	*ft_ltoa(long int ln)
{
	long long int	lln;
	char			*ltoa;
	int				i;
	int				du;

	lln = ln;
	ltoa = malloc(sizeof(char) * (ft_lintlen(ln) + 1));
	if (!ltoa)
		return (NULL);
	i = 0;
	if (lln < 0)
	{
		ltoa[i++] = '-';
		lln *= -1;
	}
	du = powerten(lln);
	while (du > 0)
	{
		ltoa[i++] = (lln / du) + 48;
		lln %= du;
		du /= 10;
	}
	ltoa[i] = '\0';
	return (ltoa);
}
