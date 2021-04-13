/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_textalign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:25:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/13 00:30:18 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*pf_alignleft(t_fspec *type, char *data)
{
	char	*ret;
	size_t	i;

	if (ft_strlen(data) > type->spaces)
		return (data);
	ret = malloc(sizeof(char) * (type->spaces + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i <= type->spaces && data[i])
	{
		ret[i] = data[i];
		i++;
	}
	while (i <= type->spaces)
	{
		ret[i] = type->fill;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
