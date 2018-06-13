/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stepa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:23:48 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/23 12:37:41 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stepa(t_stacks *a, t_stacks *b, char **str, int k)
{
	if ((k == 1) || (k == 2) || (k == 3))
		if (!(*str = (char *)malloc(sizeof(char) * 4)))
			return (-1);
	if (k == 4)
		if (!(*str = (char *)malloc(sizeof(char) * 5)))
			return (-1);
	if (k == 1)
		ft_stepa1(a, b, str);
	if (k == 2)
		ft_stepa2(a, b, str);
	if (k == 3)
		ft_stepa3(a, b, str);
	if (k == 4)
		ft_stepa4(a, b, str);
	return (0);
}

void	ft_stepa1(t_stacks *a, t_stacks *b, char **str)
{
	int		i;

	i = 0;
	ft_swap_s_ps(a);
	(*str)[i++] = 's';
	if ((b->begin) && (b->begin->next) && (b->begin->next->d > b->begin->d))
	{
		ft_swap_s_ps(b);
		(*str)[i++] = 's';
	}
	else
		(*str)[i++] = 'a';
	(*str)[i++] = '\n';
	(*str)[i++] = '\0';
}

void	ft_stepa2(t_stacks *a, t_stacks *b, char **str)
{
	int		i;

	i = 0;
	ft_swap_p_ps(b, a);
	(a->len)--;
	(b->len)++;
	(*str)[i++] = 'p';
	(*str)[i++] = 'b';
	(*str)[i++] = '\n';
	(*str)[i++] = '\0';
}

void	ft_stepa3(t_stacks *a, t_stacks *b, char **str)
{
	int		i;

	i = 0;
	ft_swap_r_ps(a);
	(*str)[i++] = 'r';
	if ((b->begin) && (b->end) && (b->end->d > b->begin->d))
	{
		ft_swap_r_ps(b);
		(*str)[i++] = 'r';
	}
	else
		(*str)[i++] = 'a';
	(*str)[i++] = '\n';
	(*str)[i++] = '\0';
}

void	ft_stepa4(t_stacks *a, t_stacks *b, char **str)
{
	int		i;

	i = 0;
	ft_swap_rr_ps(a);
	(*str)[i++] = 'r';
	(*str)[i++] = 'r';
	if ((b->begin) && (b->end) && (b->end->d > b->begin->d))
	{
		ft_swap_rr_ps(b);
		(*str)[i++] = 'r';
	}
	else
		(*str)[i++] = 'a';
	(*str)[i++] = '\n';
	(*str)[i++] = '\0';
}
