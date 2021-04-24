/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:09:00 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/18 17:37:01 by lrocigno         ###   ########.fr       */
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
# include <stdio.h>
# include "./libs/libft/libft.h"

# define P_FLAGS "0-"
# define P_SIZES "123456789*"
# define P_SPECS "cspdiuxX%"
# define C_NUM "pdiuxX"
# define C_ALP "cs%"

typedef struct s_fspec
{
	bool	init;
	char	fs;
	size_t	w;
	bool	p;
	size_t	l;
	char	s;
	char	*dt;
	size_t	sz;
}				t_fspec;

int		ft_printf(const char *str, ...);
char	*pf_parser(va_list args, char s);
char	*pf_textformat(t_fspec *tp);
t_fspec	*pf_newfspec(void);
void	pf_delfspec(t_fspec **del);
t_fspec	*pf_settype(const char *str, va_list args);

#endif
