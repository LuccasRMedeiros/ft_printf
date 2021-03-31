/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:26:00 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 19:31:04 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *str, const char *sub, size_t n)
{
	size_t	ih;
	size_t	in;

	ih = 0;
	in = 0;
	if (!(*sub))
		return ((char*)str);
	while (str[ih] != '\0' && ih < n)
	{
		if (str[ih] == sub[0])
		{
			while (str[ih] == sub[in] && ih < n)
			{
				ih++;
				in++;
				if (sub[in] == '\0')
					return ((char*)str + (ih - in));
			}
			ih = (ih - in);
			in = 0;
		}
		ih++;
	}
	return (NULL);
}
