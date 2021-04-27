/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocignoS <lrocigno@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/25 14:05:45 by lrocignoS        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file exists to test the ft_printf during its early development.
*/

#include <ft_printf.h>

int	main(void)
{
	int		ret;
	int		pf_ret;
	char	*phrase;
	//char	*stest;
	int		ntest;

	phrase = "%c:\t|%-*d|\n";
	//stest = "ok!";
	ntest = 9831;
	ret = ft_printf(phrase, 'f', 19, ntest);
	pf_ret = printf(phrase, 'o', 19, ntest);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
