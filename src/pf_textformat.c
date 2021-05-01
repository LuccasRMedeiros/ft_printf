/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_textformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:25:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/01 13:10:40 by lrocigno         ###   ########.fr       */
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

static char	*alignleft(size_t wd, size_t sz, char *dt)
{
	char	*ret;

	ret = ft_calloc(wd + 1, sizeof *ret);
	if (!ret)
		return (NULL);
	while (wd > 0)
	{
		if (wd > sz)
			ret[--wd] = ' ';
		else if (wd == sz)
		{
			while (sz > 0)
				ret[--wd] = dt[--sz];
		}
	}
	return (ret);
}

static char	*alignright(size_t wd, size_t sz, char *dt)
{
	char	*ret;

	ret = ft_calloc(wd + 1, sizeof *ret);
	if (!ret)
		return (NULL);
	while (wd > 0)
	{
		if (sz > 0)
			ret[--wd] = dt[--sz];
		else if (sz == 0)
		{
			while (wd > 0)
				ret[--wd] = ' ';
		}
	}
	return (ret);
}

char	*pf_textformat(t_fspec *tp)
{
	if (tp->fs == '-')
		return (alignleft(tp->w, tp->sz, tp->dt));
	else
		return (alignright(tp->w, tp->sz, tp->dt));
	return (NULL);
}
