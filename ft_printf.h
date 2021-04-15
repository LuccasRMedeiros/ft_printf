/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:09:00 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/15 08:38:10 by lrocigno         ###   ########.fr       */
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

# define P_FLAGS "-0"
# define P_WIDTH "123456789*"
# define P_PRESC "."
# define P_SPECS "cspdiuxX%"

typedef struct	s_fspec
{
	bool	init;
	char	*flags;
	int		width;
	bool	precision;
	int		length;
	char	specifier;
	char	*data;
	size_t	size;
}				t_fspec;

int		ft_printf(const char *string, ...);
char	*pf_parser(va_list args, t_fspec *type);
char	*pf_textformat(t_fspec *type, char *data);
t_fspec	*pf_newfspec(void);
void	pf_delfspec(t_fspec **del);

#endif
