/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_textformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:25:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/15 11:58:30 by lrocigno         ###   ########.fr       */
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

static void	alignright(t_fspec *type, char **ret)
{
	size_t	i;
	size_t	dt_i;
	char	f;

	i = 0;
	dt_i = 0;
	f = ft_strhvchr('0',type->flags) ? '0' : ' ';
	while (i < type->width - type->size)
	{
		*ret[i] = f;
		++i;
	}
	while (i < type->length)
	{
		*ret[i] = type->data[dt_i];
		++i;
		++dt_i;
	}
	*ret[i] = '\0';
}

static char	*numeric(t_fspec *type)
{
	size_t	len;
	char	*num;

	len = type->width + type->length;
	type->size = type->size > len ? type->size : len;
	num = malloc(sizeof *num * type->size + 1);
	if (!num)
		return (NULL);
}

static char	*alpha(char *alp)
{
	alp = NULL;
	return (NULL);
}

char		*pf_textformat(t_fspec *type)
{
	char *ret;

	ret = NULL;
	type->init = false;
	return (NULL);
}
