/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:16:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/03/29 19:26:05 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** First duplicate dst to a buffer, then free dst memmory and destroy it.
** Once the previous content is safe allocate more space to dst and finally	-
** copy the content of both temp and src, returning a pointer to the new	-
** address of dst.
*/

char	*ft_reallocncat(char *dst, char const *src)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	char	*temp;
	size_t	alloc;

	if (!dst || !src)
		return (NULL);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	temp = ft_strdup(dst);
	alloc = dst_len + src_len + 1;
	free(dst);
	dst = NULL;
	if (!(dst = (char*)malloc(sizeof(char) * alloc)))
		return (NULL);
	while (i < alloc - 1)
	{
		dst[i] = (i < dst_len ? temp[i] : src[i - dst_len]);
		i++;
	}
	free(temp);
	dst[i] = '\0';
	return (dst);
}
