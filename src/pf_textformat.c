/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_textformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:25:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/18 12:17:25 by lrocigno         ###   ########.fr       */
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

static char	*alignleft(size_t sz, size_t ln, char f, char *dt)
{
	size_t	ds;
	char	*ret;

	ds = ft_strlen(dt);
	ret = malloc(sizeof *ret * sz);
	if (!ret)
		return (NULL);
	ret[sz] = '\0';
	while (sz > 0)
	{
		if (sz > ln)
			ret[--sz] = ' ';
		if (sz == ln)
		{
			while (ds > 0)
				ret[--sz] = dt[--ds];
			while (ln > 0)
			{
				ret[--sz] = f;
				--ln;
			}
		}
	}
	return (ret);
}

static char	*alignright(size_t sz, size_t ln, char f, char *dt)
{
	size_t	ds;
	char	*ret;

	ds = ft_strlen(dt);
	ret = malloc(sizeof *ret * sz);
	if (!ret)
		return (NULL);
	ret[sz] = '\0';
	while (sz > 0)
	{
		if (ds > 0)
			ret[--sz] = dt[--ds];
		if (ds == 0)
		{
			while (ln > 0)
			{
				ret[--sz] = f;
				--ln;
			}
			while (sz > 0)
				ret[--sz] = ' ';
		}
	}
	return (ret);
}

char		*pf_textformat(t_fspec *tp)
{
	char *ret;
	char fill;

	ret = NULL;
	fill = ft_strhvchr(tp->fs, "0") ? '0' : ' ';
	if (ft_strhvchr(tp->fs, "-"))
		alignleft(tp->sz, tp->w, fill, tp->dt);
	else
		ret = alignright(tp->sz, tp->w, fill, tp->dt);
	return (ret);
}
