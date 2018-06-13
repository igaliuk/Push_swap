/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stepb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:57:27 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/23 12:37:45 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stepb(t_stacks *a, t_stacks *b, char **str, int k)
{
	if ((k == 1) || (k == 2) || (k == 3))
		if (!(*str = (char *)malloc(sizeof(char) * 4)))
			return (-1);
	if (k == 4)
		if (!(*str = (char *)malloc(sizeof(char) * 5)))
			return (-1);
	if (k == 1)
		ft_stepb1(a, b, str);
	if (k == 2)
		ft_stepb2(a, b, str);
	if (k == 3)
		ft_stepb3(a, b, str);
	if (k == 4)
		ft_stepb4(a, b, str);
	return (0);
}

void	ft_stepb1(t_stacks *a, t_stacks *b, char **str)
{
	int		i;

	i = 0;
	ft_swap_s_ps(b);
	(*str)[i++] = 's';
	if ((a->begin) && (a->begin->next) && (a->begin->next->d < a->begin->d))
	{
		ft_swap_s_ps(a);
		(*str)[i++] = 's';
	}
	else
		(*str)[i++] = 'b';
	(*str)[i++] = '\n';
	(*str)[i++] = '\0';
}

void	ft_stepb2(t_stacks *a, t_stacks *b, char **str)
{
	int		i;

	i = 0;
	ft_swap_p_ps(a, b);
	(b->len)--;
	(a->len)++;
	(*str)[i++] = 'p';
	(*str)[i++] = 'a';
	(*str)[i++] = '\n';
	(*str)[i++] = '\0';
}

void	ft_stepb3(t_stacks *a, t_stacks *b, char **str)
{
	int		i;

	i = 0;
	ft_swap_r_ps(b);
	(*str)[i++] = 'r';
	if ((a->begin) && (a->end) && (a->end->d < a->begin->d))
	{
		ft_swap_r_ps(a);
		(*str)[i++] = 'r';
	}
	else
		(*str)[i++] = 'b';
	(*str)[i++] = '\n';
	(*str)[i++] = '\0';
}

void	ft_stepb4(t_stacks *a, t_stacks *b, char **str)
{
	int		i;

	i = 0;
	ft_swap_rr_ps(b);
	(*str)[i++] = 'r';
	(*str)[i++] = 'r';
	if ((a->begin) && (a->end) && (a->end->d < a->begin->d))
	{
		ft_swap_rr_ps(a);
		(*str)[i++] = 'r';
	}
	else
		(*str)[i++] = 'b';
	(*str)[i++] = '\n';
	(*str)[i++] = '\0';
}
