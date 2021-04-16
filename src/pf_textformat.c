/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_textformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:25:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/16 19:49:53 by lrocigno         ###   ########.fr       */
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

static void	alignleft(size_t sz, size_t ln, char f, char *dt, char **ret)
{
	size_t	i;

	i = 0;
	*ret[sz] = '\0';
	while (sz > 0)
	{
		*ret[--sz] = ' ';
		if (sz == ln)
			while (sz > 0)
				*ret[--sz] = ln == 0 ? f : dt[--ln];
	}
}

static void	alignright(size_t sz, size_t ln, char f, char *dt, char **ret)
{
	size_t	i;
	size_t	ds;

	i = 0;
	ds = ft_strlen(dt);
	*ret[sz] = '\0';
	while (sz > 0)
	{
		if (ds > 0)
			*ret[--sz] = dt[--ds];
		else
			*ret[--sz] = f;
		if (ln == 0)
			while (sz > 0)
				*ret[--sz] = ' ';
	}
}

char		*pf_textformat(t_fspec *tp)
{
	char *ret;
	char fill;

	ret = NULL;
	ret = ft_calloc(tp->sz + 1, sizeof *ret * tp->sz + 1);
	if (!ret)
		return (NULL);
	fill = ft_strhvchr(tp->fs, "0") ? '0' : ' ';
	if (ft_strhvchr(tp->fs, "-"))
		alignleft(tp->sz, tp->w, fill, tp->dt, &ret);
	else
		alignright(tp->sz, tp->w, fill, tp->dt, &ret);
	return (ret);
}
