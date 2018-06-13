/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:57:02 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/15 16:20:31 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_lstnew_ps(t_stacks *st)
{
	if ((st->tmp1 = (t_list2 *)malloc(sizeof(t_list2))) == NULL)
		return (-1);
	st->tmp1->next = NULL;
	st->tmp1->prev = NULL;
	return (0);
}

void	ft_lstadd_ps(t_stacks *st)
{
	if (!(st->begin))
	{
		st->tmp1->next = NULL;
		st->tmp1->prev = NULL;
		st->begin = st->tmp1;
		st->end = st->tmp1;
		return ;
	}
	st->tmp2 = st->begin;
	st->begin = st->tmp1;
	st->begin->next = st->tmp2;
	st->begin->prev = NULL;
	st->tmp2->prev = st->begin;
}

void	ft_lstaddback_ps(t_stacks *st)
{
	if (!(st->begin))
	{
		st->tmp1->next = NULL;
		st->tmp1->prev = NULL;
		st->begin = st->tmp1;
		st->end = st->tmp1;
		return ;
	}
	st->tmp2 = st->end;
	st->end = st->tmp1;
	st->tmp2->next = st->end;
	st->end->prev = st->tmp2;
	st->end->next = NULL;
}

void	ft_lstdel_ps(t_stacks *st)
{
	while (st->begin)
	{
		st->tmp1 = st->begin;
		st->begin = st->begin->next;
		free(st->tmp1);
		st->tmp1 = NULL;
	}
}

void	ft_lstlen_ps(t_stacks *st)
{
	st->tmp1 = st->begin;
	while (st->tmp1)
	{
		(st->len)++;
		st->tmp1 = st->tmp1->next;
	}
}
