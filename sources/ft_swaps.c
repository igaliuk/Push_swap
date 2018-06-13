/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:24:27 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/15 16:19:54 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_s_ps(t_stacks *st)
{
	if (st->begin && st->begin->next)
	{
		st->tmp1 = st->begin;
		st->tmp2 = st->begin->next;
		st->tmp1->next = st->tmp2->next;
		st->tmp1->prev = st->tmp2;
		st->begin = st->tmp2;
		st->begin->next = st->tmp1;
		st->begin->prev = NULL;
		if (st->tmp2 != st->end)
		{
			st->tmp2 = st->tmp1->next;
			st->tmp2->prev = st->tmp1;
		}
		else
			st->end = st->tmp1;
	}
}

void	ft_swap_p_ps(t_stacks *std, t_stacks *sts)
{
	if (sts->begin)
	{
		std->tmp1 = sts->begin;
		sts->begin = sts->begin->next;
		if (sts->begin)
			sts->begin->prev = NULL;
		ft_lstadd_ps(std);
	}
}

void	ft_swap_r_ps(t_stacks *st)
{
	if (st->begin && st->begin->next)
	{
		st->tmp1 = st->begin;
		st->begin = st->begin->next;
		st->begin->prev = NULL;
		ft_lstaddback_ps(st);
	}
}

void	ft_swap_rr_ps(t_stacks *st)
{
	if (st->begin && st->begin->next)
	{
		st->tmp1 = st->end;
		st->end = st->end->prev;
		st->end->next = NULL;
		ft_lstadd_ps(st);
	}
}
