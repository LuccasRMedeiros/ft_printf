/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:09:00 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/01 21:46:46 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is a sub header of libft.h, it lists almost everything that is needed  -
** to make ft_printf work properly.
** Here are listed functions that are exclusive for ft_printf                  -
** (ft_printf_parser for exemple), and definitions that are needed by ft_printf.
*/

#include <stdarg.h>

#define P_CONVS "cspdiuxX%"
#define P_FLAGS "-0.*"

int	ft_printf_parser(const char c);
