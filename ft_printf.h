/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:09:00 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/11 10:51:33 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is a sub header of libft.h, it lists almost everything that is needed  -
** to make ft_printf work properly.
** Here are listed functions that are exclusive for ft_printf                  -
** (ft_printf_parser for exemple), and definitions that are needed only by     -
** ft_printf.
** P_CONVS more than tells what are the format specifiers, carries positions of-
**  the specifiers according the ones who uses functions without any kind of   -
** treatment needed before printing. The positions are inverse to status (see  -
** ft_printf) to avoid an undesirable conversion inside the global variable.
** P_FLAGS are used to formating the format specifiers. Consider each symbols  -
** as masks.
*/

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include "./libs/libft/libft.h"

# define P_CONVS "Xxpusidc"
# define P_FLAGS "-.*"

typedef struct	s_fspec
{
	bool	init;
	char	align;
	bool	fill;
	size_t	spaces;
	char	format;
	char	*output;
}				t_fspec;

int		ft_printf(const char *string, ...);
char	*pf_parser(va_list args, unsigned int type);
t_fspec	*new_fspec(void);
void	destroy_fspec(t_fspec *del);

#endif
