/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:09:00 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/07 11:42:08 by lrocigno         ###   ########.fr       */
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
*/

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>

# define P_CONVS "Xxpusidc%"
# define P_FLAGS "-0.*"

#endif
