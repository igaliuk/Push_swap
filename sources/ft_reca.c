/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reca.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:43:20 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/22 20:11:42 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_reca(t_stacks *a, t_stacks *b, t_list **lst, t_v v)
{
	if (!ft_checksorta(a) && (v.va > 3))
	{
		v = ft_halfa(a, b, lst, v);
		if (v.ve == -1)
			return (-1);
		if (ft_reca(a, b, lst, v) == -1)
			return (-1);
		if (ft_recb(a, b, lst, v) == -1)
			return (-1);
	}
	return (ft_sorta(a, b, lst, v.va));
}

t_v		ft_halfa(t_stacks *a, t_stacks *b, t_list **lst, t_v v)
{
	if (ft_badsort(a, lst, 1) == -1)
	{
		v.ve = -1;
		return (v);
	}
	v.vb = b->len;
	if (a->len == v.va)
		v.vk = ft_checkhalf(a, ((int *)((*lst)->content))[v.va / 2 - 1], 1);
	v = ft_halfa1(a, b, lst, v);
	if (v.ve == -1)
		return (v);
	v.vk = 0;
	v.vb = b->len - v.vb;
	v.va -= v.vb;
	if (a->len != v.va)
		v = ft_halfa2(a, b, lst, v);
	return (v);
}

t_v		ft_halfa1(t_stacks *a, t_stacks *b, t_list **lst, t_v v)
{
	t_list	*tmp;
	size_t	i;
	int		k;

	i = 0;
	while ((i < v.va) && (a->len > 3))
	{
		if (!(tmp = ft_lstnew(NULL, 0)))
		{
			v.ve = -1;
			return (v);
		}
		if (a->begin->d <= ((int *)((*lst)->content))[v.va / 2 - 1])
			k = 2;
		if ((a->begin->d > ((int *)((*lst)->content))[v.va / 2 - 1]) && !(v.vk))
			k = 3;
		if ((a->begin->d > ((int *)((*lst)->content))[v.va / 2 - 1]) && v.vk)
			k = 4;
		if ((v.ve = ft_stepa(a, b, (char **)(&(tmp->content)), k)) == -1)
			return (v);
		ft_lstaddback(lst, tmp);
		i++;
	}
	return (v);
}

t_v		ft_halfa2(t_stacks *a, t_stacks *b, t_list **lst, t_v v)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	while (i < v.va)
	{
		if (!(tmp = ft_lstnew(NULL, 0)))
		{
			v.ve = -1;
			return (v);
		}
		if ((v.ve = ft_stepa(a, b, (char **)(&(tmp->content)), 4)) == -1)
			return (v);
		ft_lstaddback(lst, tmp);
		i++;
	}
	return (v);
}
