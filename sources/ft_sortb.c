/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:09:18 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/15 16:12:45 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sortb(t_stacks *a, t_stacks *b, t_list **lst, int k)
{
	if ((k == 1) && (b->begin))
		return (ft_caseb(a, b, lst, 2));
	if ((k == 2) && (b->begin) && (b->begin->next))
	{
		if (b->begin->d > b->begin->next->d)
			return (ft_caseb(a, b, lst, 22));
		return (ft_caseb(a, b, lst, 221));
	}
	if ((k == 3) && (b->begin) && (b->begin->next) && (b->begin->next->next))
		return (ft_sortb3(a, b, lst));
	return (0);
}

int		ft_sortb3(t_stacks *a, t_stacks *b, t_list **lst)
{
	if (b->len == 3)
	{
		if (b->begin->next->next->d < b->begin->next->d)
			return (ft_sortblast3_1(a, b, lst));
		else
			return (ft_sortblast3_2(a, b, lst));
	}
	else
	{
		if (b->begin->next->next->d < b->begin->next->d)
			return (ft_sortb3_1(a, b, lst));
		else
			return (ft_sortb3_2(a, b, lst));
	}
	return (0);
}

int		ft_sortb3_1(t_stacks *a, t_stacks *b, t_list **lst)
{
	if ((b->begin->next->next->d < b->begin->d)
		&& (b->begin->next->next->d < b->begin->next->d)
		&& (b->begin->d < b->begin->next->d))
		return (ft_caseb(a, b, lst, 2221));
	if ((b->begin->next->next->d > b->begin->d)
		&& (b->begin->next->next->d < b->begin->next->d)
		&& (b->begin->d < b->begin->next->d))
		return (ft_caseb(a, b, lst, 24223));
	if ((b->begin->next->next->d < b->begin->d)
		&& (b->begin->next->next->d < b->begin->next->d)
		&& (b->begin->d > b->begin->next->d))
		return (ft_caseb(a, b, lst, 222));
	return (0);
}

int		ft_sortb3_2(t_stacks *a, t_stacks *b, t_list **lst)
{
	if ((b->begin->next->next->d < b->begin->d)
		&& (b->begin->next->next->d > b->begin->next->d)
		&& (b->begin->d > b->begin->next->d))
		return (ft_caseb(a, b, lst, 2212));
	if ((b->begin->next->next->d > b->begin->d)
		&& (b->begin->next->next->d > b->begin->next->d)
		&& (b->begin->d > b->begin->next->d))
		return (ft_caseb(a, b, lst, 224213));
	if ((b->begin->next->next->d > b->begin->d)
		&& (b->begin->next->next->d > b->begin->next->d)
		&& (b->begin->d < b->begin->next->d))
		return (ft_caseb(a, b, lst, 242213));
	return (0);
}

int		ft_caseb(t_stacks *a, t_stacks *b, t_list **lst, int k)
{
	t_list	*tmp;

	while (k)
	{
		if (!(tmp = ft_lstnew(NULL, 0)))
			return (-1);
		if (ft_stepb(a, b, (char **)(&(tmp->content)), k % 10) == -1)
			return (-1);
		ft_lstaddback(lst, tmp);
		k /= 10;
	}
	return (0);
}
