/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:45:28 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/22 17:10:47 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_startsort(t_stacks *a, t_stacks *b, t_list **lst)
{
	t_v		v;

	v.va = a->len;
	v.vb = 0;
	v.ve = 0;
	v.vk = 0;
	if (ft_reca(a, b, lst, v) == -1)
		return (-1);
	while (b->len)
		if (ft_caseb(a, b, lst, 2) == -1)
			return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_stacks	a;
	t_stacks	b;
	t_list		*lst;

	if (argc == 1)
		ft_usa(1);
	ft_zerostack(&a);
	ft_zerostack(&b);
	ft_readstacka(argc, argv, &a, NULL);
	ft_checkstacka(&a);
	ft_lstlen_ps(&a);
	if (!(lst = ft_lstnew(NULL, 0)))
		ft_error(&a);
	if (ft_startsort(&a, &b, &lst) == -1)
		ft_error(&a);
	ft_updatesort(&lst);
	ft_tofin(&lst);
	ft_lstdel_ps(&a);
	ft_lstdel_ps(&b);
	ft_lstdel(&lst, &ft_del);
	return (0);
}
