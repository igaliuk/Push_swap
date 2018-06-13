/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortblast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:07:53 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/15 16:17:41 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sortblast3_1(t_stacks *a, t_stacks *b, t_list **lst)
{
	if ((b->begin->next->next->d < b->begin->d)
		&& (b->begin->next->next->d < b->begin->next->d)
		&& (b->begin->d < b->begin->next->d))
		return (ft_caseb(a, b, lst, 2221));
	if ((b->begin->next->next->d > b->begin->d)
		&& (b->begin->next->next->d < b->begin->next->d)
		&& (b->begin->d < b->begin->next->d))
		return (ft_caseb(a, b, lst, 2223));
	if ((b->begin->next->next->d < b->begin->d)
		&& (b->begin->next->next->d < b->begin->next->d)
		&& (b->begin->d > b->begin->next->d))
		return (ft_caseb(a, b, lst, 222));
	return (0);
}

int		ft_sortblast3_2(t_stacks *a, t_stacks *b, t_list **lst)
{
	if ((b->begin->next->next->d < b->begin->d)
		&& (b->begin->next->next->d > b->begin->next->d)
		&& (b->begin->d > b->begin->next->d))
		return (ft_caseb(a, b, lst, 2212));
	if ((b->begin->next->next->d > b->begin->d)
		&& (b->begin->next->next->d > b->begin->next->d)
		&& (b->begin->d > b->begin->next->d))
		return (ft_caseb(a, b, lst, 2224));
	if ((b->begin->next->next->d > b->begin->d)
		&& (b->begin->next->next->d > b->begin->next->d)
		&& (b->begin->d < b->begin->next->d))
		return (ft_caseb(a, b, lst, 22124));
	return (0);
}
