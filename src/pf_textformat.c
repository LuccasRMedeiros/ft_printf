/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_textformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:25:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/13 20:33:05 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pf_textalign will firstly test the size of the data length against the      -
** number of spaces informed by the user. Case data length be greater than the -
** amount of spaces, the function do nothing and return the received input,    -
** otherwise it will format properly as the user want it, then it returns a    -
** formated and null terminated string.
** The static fuctions alignleft and alignright are void and do not return,    -
** instead they receive a pointer to pointer to char so only pf_textalign needs-
**  to allocate memory for the string and make error treatment for malloc.
*/

#include <ft_printf.h>

static void	alignleft(t_fspec *type, char *data, char **ret)
{
	size_t	i;

	i = 0;
	while (i <= type->spaces && data[i])
	{
		*ret[i] = data[i];
		i++;
	}
	while (i <= type->spaces)
	{
		*ret[i] = type->fill;
		i++;
	}
	*ret[i] = '\0';
}

static void	alignright(t_fspec *type, char *data, char **ret)
{
	size_t	i;
	size_t	dt_len;
	size_t	dt_i;

	i = 0;
	dt_len = ft_strlen(data);
	dt_i = 0;
	while (i <= type->spaces - dt_len)
	{
		*ret[i] = type->fill;
		i++;
	}
	while (i <= type->spaces)
	{
		*ret[i] = data[dt_i];
		i++;
		dt_i++;
	}
	*ret[i] = '\0';
}

char		*pf_textformat(t_fspec *type, char *data)
{
	char	*ret;

	if (ft_strlen(data) > type->spaces)
		return (data);
	ret = malloc(sizeof(char) * (type->spaces + 1));
	if (!ret)
		return (NULL);
	if (!type->align)
		alignleft(type, data, &ret);
	else
		alignright(type, data, &ret);
	return (ret);
}
