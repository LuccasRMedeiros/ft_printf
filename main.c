/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/03 11:04:30 by lrocigno         ###   ########.fr       */
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
	int		pf_ret;
	int		ret;
	char	*phrase;

	phrase = ft_strdup("ultimate2 %*d %*s %*x %*X %*i %*u\n");
	ret = ft_printf(phrase, 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
	pf_ret = printf(phrase, 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	free(phrase);
	return (0);
}
