/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:29:32 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/18 18:32:13 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ststatus(t_stacks *st)
{
	if (st->begin)
	{
		st->tmp1 = st->begin;
		while (st->tmp1->next)
		{
			ft_putnbr(st->tmp1->d);
			write(1, " ", 1);
			st->tmp1 = st->tmp1->next;
		}
		ft_putnbr(st->tmp1->d);
	}
}

void	ft_flags(t_stacks *a, t_stacks *b, t_fl *fl, int k)
{
	if (k == 2)
	{
		write(1, "\e[33mNumber of operations: \e[1m", 31);
		ft_putnbr(fl->l);
		write(1, "\e[0m\n", 5);
		return ;
	}
	if (fl->flv)
	{
		write(1, "\e[1mA: \e[0m", 11);
		ft_ststatus(a);
		write(1, "\n\e[1mB: \e[0m", 12);
		ft_ststatus(b);
		write(1, "\n", 1);
		if (k)
			write(1, "\n", 1);
	}
}
