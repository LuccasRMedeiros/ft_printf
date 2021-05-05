/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/05 13:07:36 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file exists to test the ft_printf during its early development.
*/

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	//int		pf_ret;
	int		ret;
	
	ret = ft_printf("%%");
	//pf_ret = printf("%.0p\n");
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	//printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
