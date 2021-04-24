/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocignoS <lrocigno@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/24 17:59:12 by lrocignoS        ###   ########.fr       */
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
	char	*stest;
	int		ntest;

	phrase = "%-015.7d %-.19s %%\e[0;32mend\e[0m\n";
	stest = "ok!";
	ntest = 9831;
	ret = ft_printf(phrase, ntest, stest);
	pf_ret = printf(phrase, ntest, stest);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
