/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/14 23:21:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file exists to test the printf during its early development.
** To avoid norminette acusing errors that are unecessary to be corrected (as  -
** main function will not be included with the files of the final program) the -
** main is written accord to the norm, but that's not necessary.
*/

#include <ft_printf.h>
#include <stdio.h>

int	main(void)
{
	int				ret;
	char			*phrase;
	//char			*test;
	//int				test1;
	//int				pf_ret;
	
	phrase = "Let's see and compare:%5-7-3*d\e[0;32mend\e[0m\n\n";
	//test = "123456789"
	//test1 = 1;
	ret = ft_printf(phrase);
	//pf_ret = printf(phrase, test1);//, test1);
	//printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	//printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
