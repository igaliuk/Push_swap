/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:46:30 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/15 16:15:20 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_zerostack(t_stacks *st)
{
	st->begin = NULL;
	st->end = NULL;
	st->tmp1 = NULL;
	st->tmp2 = NULL;
	st->len = 0;
}
