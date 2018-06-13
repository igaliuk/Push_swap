/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:09:35 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/18 19:30:09 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_usa(int k)
{
	if (k == 1)
	{
		write(1, "usage: ./push_swap \e[1md1 d2 ...\e[0m\n", 37);
		write(1,
			"       [\e[1md1 d2 ...\e[0m - numbers of integers]\n", 49);
	}
	if (k == 2)
	{
		write(1, "usage: ./checker \e[1m-vl d1 d2 ...\e[0m\n", 39);
		write(1,
			"       [\e[1m-v\e[0m - stack's status after each operation]\n",
			58);
		write(1,
			"       [\e[1m-l\e[0m - number of operations]\n", 43);
		write(1,
			"       [\e[1md1 d2 ...\e[0m - numbers of integers]\n", 49);
	}
	exit(0);
}
