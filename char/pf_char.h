/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:56:35 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/09 23:26:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is a subheader of ft_printf, as it is just to be used by ft_printf ONLY.
** Here a concept of a "char" is used to implement the format specification of -
** the original printf.
*/

#define MASK "\%-0c"

typedef struct s_fspec_char
{
	char	init;
	char	signal;
	int		space;
	char	format;
}
