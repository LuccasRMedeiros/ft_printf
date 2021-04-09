/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/09 12:35:16 by lrocigno         ###   ########.fr       */
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

int	main()
{
	int		ret;
	int		pf_ret;
	char	*phrase;
	int		test_num;
	
	phrase = "Let's see and compare: %d\n";
	test_num = 123;
	ret = ft_printf(phrase, test_num);
	pf_ret = printf(phrase, test_num);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
