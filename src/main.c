/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/01 19:16:56 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file exists to test the printf during its early development.
** To avoid norminette acusing errors that are unecessary to be corrected (as  -
** main function will not be included with the files of the final program).
*/

#include <libft.h>
#include <stdio.h>

int	main()
{
	int	ret;
	int pf_ret;

	ret = ft_printf("Let's see and compare: %d\n", 1);
	pf_ret = printf("Let's see and compare: %d\n", 1);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
