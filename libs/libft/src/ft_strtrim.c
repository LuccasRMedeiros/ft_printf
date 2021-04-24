/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 22:10:10 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 19:31:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_haschar(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		stt;
	int		end;
	size_t	i;
	char	*trim;

	if (!s1)
		return (NULL);
	stt = 0;
	while (ft_haschar(set, s1[stt]))
		stt++;
	end = ft_strlen(s1) - 1;
	while (end > stt && ft_haschar(set, s1[end]))
		end--;
	i = 0;
	trim = malloc(sizeof(char) * (end - stt + 2));
	if (!trim)
		return (NULL);
	while (stt <= end)
	{
		trim[i] = s1[stt];
		i++;
		stt++;
	}
	trim[i] = '\0';
	return (trim);
}
