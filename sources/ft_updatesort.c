/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_updatesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:03:06 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/15 16:15:04 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_updatesort(t_list **lst)
{
	t_list	*tmp;
	int		k;

	if ((tmp = (*lst)->next) == NULL)
		return ;
	k = 1;
	while (k)
	{
		k = 0;
		tmp = (*lst)->next;
		while (tmp->next)
		{
			ft_upchg(lst, &tmp);
			ft_updelandchg(lst, &tmp);
			if ((k = ft_updel(lst, &tmp)) == 1)
				break ;
			tmp = tmp->next;
		}
	}
}

void	ft_delorchg(t_list **lst, t_list **tmp, int i)
{
	t_list	*tmp2;

	if ((i == 0) || (i == 1) || (i == 2))
	{
		tmp2 = (*tmp)->next;
		if ((i == 1) || (i == 2))
			((char *)((*tmp)->content))[i] = ((char *)((*tmp)->content))[i - 1];
		ft_lstdeloneany(tmp, &tmp2, &ft_del);
		if (i == 0)
			ft_lstdeloneany(lst, tmp, &ft_del);
	}
	if (i == 3)
	{
		tmp2 = ((*tmp)->next->next);
		((char *)((*tmp)->content))[0] = 's';
		ft_lstdeloneany(tmp, &tmp2, &ft_del);
	}
}

void	ft_upchg(t_list **lst, t_list **tmp)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = (char *)((*tmp)->content);
	str2 = (char *)((*tmp)->next->content);
	if (((!ft_strcmp(str1, "sa\n")) && (!ft_strcmp(str2, "sb\n")))
		|| ((!ft_strcmp(str1, "sb\n")) && (!ft_strcmp(str2, "sa\n")))
		|| ((!ft_strcmp(str1, "ra\n")) && (!ft_strcmp(str2, "rb\n")))
		|| ((!ft_strcmp(str1, "rb\n")) && (!ft_strcmp(str2, "ra\n")))
		|| ((!ft_strcmp(str1, "rra\n")) && (!ft_strcmp(str2, "rrb\n")))
		|| ((!ft_strcmp(str1, "rrb\n")) && (!ft_strcmp(str2, "rra\n"))))
	{
		i = 0;
		while (str1[i] != '\n')
			i++;
		ft_delorchg(lst, tmp, i - 1);
	}
}

int		ft_updel(t_list **lst, t_list **tmp)
{
	char	*str1;
	char	*str2;

	str1 = (char *)((*tmp)->content);
	str2 = (char *)((*tmp)->next->content);
	if (((!ft_strcmp(str1, "sa\n")) && (!ft_strcmp(str2, "sa\n")))
		|| ((!ft_strcmp(str1, "sb\n")) && (!ft_strcmp(str2, "sb\n")))
		|| ((!ft_strcmp(str1, "ss\n")) && (!ft_strcmp(str2, "ss\n")))
		|| ((!ft_strcmp(str1, "pa\n")) && (!ft_strcmp(str2, "pb\n")))
		|| ((!ft_strcmp(str1, "pb\n")) && (!ft_strcmp(str2, "pa\n")))
		|| ((!ft_strcmp(str1, "ra\n")) && (!ft_strcmp(str2, "rra\n")))
		|| ((!ft_strcmp(str1, "rra\n")) && (!ft_strcmp(str2, "ra\n")))
		|| ((!ft_strcmp(str1, "rb\n")) && (!ft_strcmp(str2, "rrb\n")))
		|| ((!ft_strcmp(str1, "rrb\n")) && (!ft_strcmp(str2, "rb\n")))
		|| ((!ft_strcmp(str1, "rr\n")) && (!ft_strcmp(str2, "rrr\n")))
		|| ((!ft_strcmp(str1, "rrr\n")) && (!ft_strcmp(str2, "rr\n"))))
	{
		ft_delorchg(lst, tmp, 0);
		return (1);
	}
	return (0);
}

void	ft_updelandchg(t_list **lst, t_list **tmp)
{
	char	*str1;
	char	*str2;
	char	*str3;

	if ((*tmp)->next->next)
	{
		str1 = (char *)((*tmp)->content);
		str2 = (char *)((*tmp)->next->content);
		str3 = (char *)((*tmp)->next->next->content);
		if (((!ft_strcmp(str1, "ra\n")) && (!ft_strcmp(str2, "pb\n"))
				&& (!ft_strcmp(str3, "rra\n")))
			|| ((!ft_strcmp(str1, "rb\n")) && (!ft_strcmp(str2, "pa\n"))
				&& (!ft_strcmp(str3, "rrb\n"))))
		{
			ft_delorchg(lst, tmp, 3);
		}
	}
}
