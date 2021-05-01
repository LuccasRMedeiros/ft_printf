/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/01 20:29:29 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file exists to test the ft_printf during its early development.
*/

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	//int		pf_ret;
	int		ret;
	//char	*phrase;

	//phrase = "%05%\n";
	ret = ft_printf("%-70.193x%-140c%168c%026.51%%0125.119X\n", 1102840003u, -50, -17, 3721437512u);
	//pf_ret = printf("%-70.193x%-140c%168c%026.51%%0125.119X\n", 1102840003u, -50, -17, 3721437512u);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	//printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
