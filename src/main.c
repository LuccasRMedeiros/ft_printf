/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/18 12:20:31 by lrocigno         ###   ########.fr       */
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
	char			*stest;
	int				ntest;
	int				pf_ret;
	
	phrase = "Let's see and compare: %d\n";
	stest = "ok!";
	ntest = 9831;
	ret = ft_printf(phrase, ntest);
	pf_ret = printf(phrase, ntest);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
