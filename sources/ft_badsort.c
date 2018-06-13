/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_badsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:38:51 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/22 18:46:25 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_badsort(t_stacks *st, t_list **lst, int z)
{
	size_t	i;
	int		*c;

	if ((*lst)->content)
	{
		free((*lst)->content);
		(*lst)->content = NULL;
	}
	if (!(c = (int *)malloc(sizeof(int) * st->len)))
		return (-1);
	st->tmp1 = st->begin;
	i = 0;
	while (st->tmp1)
	{
		c[i++] = st->tmp1->d;
		st->tmp1 = st->tmp1->next;
	}
	ft_intsort(&c, st->len, z);
	(*lst)->content = c;
	(*lst)->content_size = st->len;
	return (0);
}

int		ft_checkhalf(t_stacks *st, int z, int k)
{
	int		i;
	int		p;

	st->tmp1 = st->end;
	i = 1;
	while (st->tmp1)
	{
		if (((k == 1) && (st->tmp1->d <= z)) || ((k == 2) && (st->tmp1->d > z)))
			p = i;
		i++;
		st->tmp1 = st->tmp1->prev;
	}
	if (i / 2 >= p)
		return (1);
	return (0);
}
