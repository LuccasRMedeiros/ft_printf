/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:21:01 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/05 14:10:51 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

bool	pf_error(const char *str)
{
	size_t	i;
	char	*test;

	if (!str)
		return (false);
	i = 0;
	test = ft_strchr(str, '%');
	if (!test)
		return (false);
	while (test[i + 1] != '\0')
	{
		++i;
		if (ft_strhvchr(P_SPECS, test[i]))
			return (pf_error(test + i + 1));
	}
	return (true);
}
