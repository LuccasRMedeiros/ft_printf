/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/16 23:42:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file exists to test the printf during its early development.
*/

#include <ft_printf.h>

int	main(void)
{
	int				ret;
	char			*phrase;
	char			*test;
	int				test1;
	int				pf_ret;
	
	phrase = "Let's see and compare: %c %5d %s\n";
	test = "ok!";
	test1 = 9831;
	ret = ft_printf(phrase, 'f', test1, test);
	pf_ret = printf(phrase, 'o', test1, test);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
