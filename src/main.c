/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/19 11:18:31 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file exists to test the ft_printf during its early development.
*/

#include <ft_printf.h>

int	main(void)
{
	int				ret;
	int				pf_ret;
	char			*phrase;
	char			*stest;
	int				ntest;

	phrase = "Let's see and compare: %015.7d %-s %%\e[0;32mend\e[0m\n";
	stest = "ok!";
	ntest = 9831;
	ret = ft_printf(phrase, ntest, stest);
	pf_ret = printf(phrase, ntest, stest);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
