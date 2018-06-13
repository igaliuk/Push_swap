/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:46:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/15 16:22:59 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sorta(t_stacks *a, t_stacks *b, t_list **lst, int k)
{
	if ((k == 1) && (a->begin))
		return (0);
	if ((k == 2) && (a->begin) && (a->begin->next))
	{
		if (a->begin->d < a->begin->next->d)
			return (0);
		return (ft_casea(a, b, lst, 1));
	}
	if ((k == 3) && (a->begin) && (a->begin->next) && (a->begin->next->next))
		return (ft_sorta3(a, b, lst));
	return (0);
}

int		ft_sorta3(t_stacks *a, t_stacks *b, t_list **lst)
{
	if (a->len == 3)
	{
		if (a->begin->next->next->d > a->begin->next->d)
			return (ft_sortalast3_1(a, b, lst));
		else
			return (ft_sortalast3_2(a, b, lst));
	}
	else
	{
		if (a->begin->next->next->d > a->begin->next->d)
			return (ft_sorta3_1(a, b, lst));
		else
			return (ft_sorta3_2(a, b, lst));
	}
	return (0);
}

int		ft_sorta3_1(t_stacks *a, t_stacks *b, t_list **lst)
{
	if ((a->begin->next->next->d > a->begin->d)
		&& (a->begin->next->next->d > a->begin->next->d)
		&& (a->begin->d > a->begin->next->d))
		return (ft_casea(a, b, lst, 1));
	if ((a->begin->next->next->d < a->begin->d)
		&& (a->begin->next->next->d > a->begin->next->d)
		&& (a->begin->d > a->begin->next->d))
		return (ft_casea(a, b, lst, 4131));
	return (0);
}

int		ft_sorta3_2(t_stacks *a, t_stacks *b, t_list **lst)
{
	if ((a->begin->next->next->d > a->begin->d)
		&& (a->begin->next->next->d < a->begin->next->d)
		&& (a->begin->d < a->begin->next->d))
		return (ft_casea(a, b, lst, 413));
	if ((a->begin->next->next->d < a->begin->d)
		&& (a->begin->next->next->d < a->begin->next->d)
		&& (a->begin->d < a->begin->next->d))
		return (ft_casea(a, b, lst, 1413));
	if ((a->begin->next->next->d < a->begin->d)
		&& (a->begin->next->next->d < a->begin->next->d)
		&& (a->begin->d > a->begin->next->d))
		return (ft_casea(a, b, lst, 14131));
	return (0);
}

int		ft_casea(t_stacks *a, t_stacks *b, t_list **lst, int k)
{
	t_list	*tmp;

	while (k)
	{
		if (!(tmp = ft_lstnew(NULL, 0)))
			return (-1);
		if (ft_stepa(a, b, (char **)(&(tmp->content)), k % 10) == -1)
			return (-1);
		ft_lstaddback(lst, tmp);
		k /= 10;
	}
	return (0);
}
