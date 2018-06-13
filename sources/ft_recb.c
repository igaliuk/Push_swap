/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:02:16 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/22 20:13:01 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_recb(t_stacks *a, t_stacks *b, t_list **lst, t_v v)
{
	if (!ft_checksortb(b) && v.vb > 3)
	{
		v = ft_halfb(a, b, lst, v);
		if (v.ve == -1)
			return (-1);
		if (ft_reca(a, b, lst, v) == -1)
			return (-1);
		if (v.vb > 3)
			if (ft_recb(a, b, lst, v) == -1)
				return (-1);
	}
	return (ft_sortb(a, b, lst, v.vb));
}

t_v		ft_halfb(t_stacks *a, t_stacks *b, t_list **lst, t_v v)
{
	if (ft_badsort(b, lst, -1) == -1)
	{
		v.ve = -1;
		return (v);
	}
	v.va = a->len;
	if (b->len == v.vb)
		v.vk = ft_checkhalf(b, ((int *)((*lst)->content))[v.vb / 2 - 1], 2);
	v = ft_halfb1(a, b, lst, v);
	if (v.ve == -1)
		return (v);
	v.vk = 0;
	v.va = a->len - v.va;
	v.vb -= v.va;
	if (b->len != v.vb)
		v = ft_halfb2(a, b, lst, v);
	return (v);
}

t_v		ft_halfb1(t_stacks *a, t_stacks *b, t_list **lst, t_v v)
{
	t_list	*tmp;
	size_t	i;
	int		k;

	i = 0;
	while (i < v.vb)
	{
		if (!(tmp = ft_lstnew(NULL, 0)))
		{
			v.ve = -1;
			return (v);
		}
		if (b->begin->d > ((int *)((*lst)->content))[v.vb / 2])
			k = 2;
		if ((b->begin->d <= ((int *)((*lst)->content))[v.vb / 2]) && !(v.vk))
			k = 3;
		if ((b->begin->d <= ((int *)((*lst)->content))[v.vb / 2]) && v.vk)
			k = 4;
		if ((v.ve = ft_stepb(a, b, (char **)(&(tmp->content)), k)) == -1)
			return (v);
		ft_lstaddback(lst, tmp);
		i++;
	}
	return (v);
}

t_v		ft_halfb2(t_stacks *a, t_stacks *b, t_list **lst, t_v v)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	while (i < v.vb)
	{
		if (!(tmp = ft_lstnew(NULL, 0)))
		{
			v.ve = -1;
			return (v);
		}
		if ((v.ve = ft_stepb(a, b, (char **)(&(tmp->content)), 4)) == -1)
			return (v);
		ft_lstaddback(lst, tmp);
		i++;
	}
	return (v);
}
