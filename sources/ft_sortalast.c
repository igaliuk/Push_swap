/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortalast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:34:58 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/15 16:17:33 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sortalast3_1(t_stacks *a, t_stacks *b, t_list **lst)
{
	if ((a->begin->next->next->d > a->begin->d)
		&& (a->begin->next->next->d > a->begin->next->d)
		&& (a->begin->d > a->begin->next->d))
		return (ft_casea(a, b, lst, 1));
	if ((a->begin->next->next->d < a->begin->d)
		&& (a->begin->next->next->d > a->begin->next->d)
		&& (a->begin->d > a->begin->next->d))
		return (ft_casea(a, b, lst, 3));
	return (0);
}

int		ft_sortalast3_2(t_stacks *a, t_stacks *b, t_list **lst)
{
	if ((a->begin->next->next->d > a->begin->d)
		&& (a->begin->next->next->d < a->begin->next->d)
		&& (a->begin->d < a->begin->next->d))
		return (ft_casea(a, b, lst, 14));
	if ((a->begin->next->next->d < a->begin->d)
		&& (a->begin->next->next->d < a->begin->next->d)
		&& (a->begin->d < a->begin->next->d))
		return (ft_casea(a, b, lst, 4));
	if ((a->begin->next->next->d < a->begin->d)
		&& (a->begin->next->next->d < a->begin->next->d)
		&& (a->begin->d > a->begin->next->d))
		return (ft_casea(a, b, lst, 41));
	return (0);
}
