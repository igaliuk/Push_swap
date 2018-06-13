/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:23:17 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/15 16:20:43 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checksorta(t_stacks *a)
{
	if (!(a->begin))
		return (0);
	a->tmp1 = a->begin;
	while (a->tmp1->next)
	{
		if (a->tmp1->d > a->tmp1->next->d)
			return (0);
		a->tmp1 = a->tmp1->next;
	}
	return (1);
}

int		ft_checksortb(t_stacks *b)
{
	if (!(b->begin))
		return (0);
	b->tmp1 = b->begin;
	while (b->tmp1->next)
	{
		if (b->tmp1->d < b->tmp1->next->d)
			return (0);
		b->tmp1 = b->tmp1->next;
	}
	return (1);
}
