/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readstacka.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:16:05 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/23 15:37:29 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_readstacka(int argc, char **argv, t_stacks *a, t_fl *fl)
{
	int		i;

	i = 1 + ft_checkflags(argc, argv, a, fl);
	while (i < argc)
	{
		if (ft_lstnew_ps(a) == -1)
			ft_error(a);
		ft_lstaddback_ps(a);
		a->tmp1->d = ft_atoi_ps(argv[i], a);
		i++;
	}
}

int		ft_atoi_ps(char *str, t_stacks *a)
{
	int			i;
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i])
	{
		if ((i == 0) && (str[i] == '-'))
		{
			sign = -1;
			i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			res = 10 * res + str[i] - '0';
		if ((res * sign < -2147483648) || (res * sign > 2147483647)
			|| str[i] < '0' || str[i] > '9')
			ft_error(a);
		i++;
	}
	return (res * sign);
}

void	ft_checkstacka(t_stacks *a)
{
	a->tmp1 = a->begin;
	while (a->tmp1->next)
	{
		a->tmp2 = a->tmp1->next;
		while (a->tmp2)
		{
			if (a->tmp1->d == a->tmp2->d)
				ft_error(a);
			a->tmp2 = a->tmp2->next;
		}
		a->tmp1 = a->tmp1->next;
	}
}
