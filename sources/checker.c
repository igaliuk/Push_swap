/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:09:35 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/18 15:59:21 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_zeroflags(t_fl *fl)
{
	fl->fll = 0;
	fl->flv = 0;
	fl->l = 0;
}

int		main(int argc, char **argv)
{
	t_stacks	a;
	t_stacks	b;
	t_fl		fl;

	if (argc == 1)
		ft_usa(2);
	ft_zerostack(&a);
	ft_zerostack(&b);
	ft_zeroflags(&fl);
	ft_readstacka(argc, argv, &a, &fl);
	ft_checkstacka(&a);
	ft_operations(&a, &b, &fl);
	if (ft_checksorta(&a) && b.begin == NULL)
		write(1, "\e[1;32mOK\n\e[0m", 14);
	else
		write(1, "\e[1;35mKO\n\e[0m", 14);
	ft_lstdel_ps(&a);
	ft_lstdel_ps(&b);
	return (0);
}
