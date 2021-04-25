/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_textformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocignoS <lrocigno@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:25:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/25 10:42:50 by lrocignoS        ###   ########.fr       */
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

static char	*alignleft(size_t wd, size_t ln, size_t sz, char *dt)
{
	char	*ret;

	ret = ft_calloc(wd, sizeof *ret * wd);
	if (!ret)
		return (NULL);
	while (wd > 0)
	{
		if (wd > ln + sz)
			ret[--wd] = ' ';
		else if (wd == ln + sz)
		{
			while (sz > 0)
				ret[--wd] = dt[--sz];
			while (ln > 0)
			{
				ret[--wd] = '0';
				--ln;
			}
		}
	}
	return (ret);
}

static char	*alignright(size_t wd, size_t ln, size_t sz, char *dt)
{
	char	*ret;

	ret = ft_calloc(wd, sizeof *ret * wd);
	if (!ret)
		return (NULL);
	while (wd > 0)
	{
		if (sz > 0)
			ret[--wd] = dt[--sz];
		else if (sz == 0)
		{
			while (ln > 0)
			{
				ret[--wd] = '0';
				--ln;
			}
			while (wd > 0)
				ret[--wd] = ' ';
		}
	}
	return (ret);
}

char	*pf_textformat(t_fspec *tp)
{
	char *ret;

	ret = NULL;
	if (tp->fs == '-')
		ret = alignleft(tp->w, tp->l, tp->sz, tp->dt);
	else
		ret = alignright(tp->w, tp->l, tp->sz, tp->dt);
	return (ret);
}
