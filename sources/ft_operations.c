/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:27:24 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/18 18:35:11 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_oper1_5(t_stacks *a, t_stacks *b, char *op)
{
	if (!(ft_strcmp(op, "sa")))
		ft_swap_s_ps(a);
	if (!(ft_strcmp(op, "sb")))
		ft_swap_s_ps(b);
	if (!(ft_strcmp(op, "ss")))
	{
		ft_swap_s_ps(a);
		ft_swap_s_ps(b);
	}
	if (!(ft_strcmp(op, "pa")))
		ft_swap_p_ps(a, b);
	if (!(ft_strcmp(op, "pb")))
		ft_swap_p_ps(b, a);
}

void	ft_oper6_11(t_stacks *a, t_stacks *b, char *op)
{
	if (!(ft_strcmp(op, "ra")))
		ft_swap_r_ps(a);
	if (!(ft_strcmp(op, "rb")))
		ft_swap_r_ps(b);
	if (!(ft_strcmp(op, "rr")))
	{
		ft_swap_r_ps(a);
		ft_swap_r_ps(b);
	}
	if (!(ft_strcmp(op, "rra")))
		ft_swap_rr_ps(a);
	if (!(ft_strcmp(op, "rrb")))
		ft_swap_rr_ps(b);
	if (!(ft_strcmp(op, "rrr")))
	{
		ft_swap_rr_ps(a);
		ft_swap_rr_ps(b);
	}
}

void	ft_operations(t_stacks *a, t_stacks *b, t_fl *fl)
{
	char	*op;
	int		k;

	while ((k = get_next_line(0, &op)) == 1)
	{
		if ((k == -1) || (ft_strcmp(op, "sa") && ft_strcmp(op, "sb")
			&& ft_strcmp(op, "ss") && ft_strcmp(op, "pa") && ft_strcmp(op, "pb")
			&& ft_strcmp(op, "ra") && ft_strcmp(op, "rb") && ft_strcmp(op, "rr")
			&& ft_strcmp(op, "rra") && ft_strcmp(op, "rrb")
			&& ft_strcmp(op, "rrr")))
		{
			ft_lstdel_ps(b);
			ft_error(a);
		}
		(fl->l)++;
		if (fl->flv)
			ft_flags(a, b, fl, 1);
		ft_oper1_5(a, b, op);
		ft_oper6_11(a, b, op);
		ft_strdel(&op);
	}
	if (fl->flv)
		ft_flags(a, b, fl, 0);
	if (fl->fll)
		ft_flags(a, b, fl, 2);
}
