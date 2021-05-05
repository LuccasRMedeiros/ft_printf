/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:21:01 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/05 12:10:09 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

bool	pf_error(const char *str)
{
	size_t	i;
	char	*test;

	i = 0;
	test = ft_strchr(str, '%');
	if (!test)
		return (false);
	while (test[i + 1] != '\0')
	{
		++i;
		if (ft_strhvchr(P_SPECS, str[i]))
			pf_error(test + i);
	}
	return (true);
}
