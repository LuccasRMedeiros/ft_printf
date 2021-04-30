/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:01:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/04/29 21:26:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file exists to test the ft_printf during its early development.
*/

#include <ft_printf.h>

int	main(void)
{
	int		pf_ret;
	int		ret;
	char	*phrase;

	phrase = " 0*%0-*d*0 0*%0*d*0 \n";
	ret = ft_printf(phrase, 21, 1021, 21, -1011);
	pf_ret = printf(phrase, 21, 1021, 21, -1011);
	printf("Return of ft_printf: \e[1;33m%d\e[0m\n", ret);
	printf("Return of printf: \e[1;33m%d\e[0m\n", pf_ret);
	return (0);
}
