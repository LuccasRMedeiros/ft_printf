/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/15 23:35:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file exists to test the printf during its early development.
*/

#include <ft_printf.h>
#include <stdio.h>

int	main(void)
{
	int				ret;
	char			*phrase;
	char			*test;
	int				test1;
	int				pf_ret;
	
	phrase = "Let's see and compare:%s %% %d\e[0;32mend\e[0m\n\n";
	test = "ok!"
	test1 = 200;
	ret = ft_printf(phrase, test, test1);
	pf_ret = printf(phrase, test, test1);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
