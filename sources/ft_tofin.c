/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tofin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:51:52 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/22 13:57:38 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_lenlen(t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = (*lst)->next;
	i = 0;
	while (tmp)
	{
		i += ft_strlen((char *)(tmp->content));
		tmp = tmp->next;
	}
	return (i + 1);
}

int		ft_tofin(t_list **lst)
{
	t_list	*tmp;
	char	*str;
	int		i;

	if ((str = (char *)malloc(sizeof(char) * (ft_lenlen(lst)))) == NULL)
		return (-1);
	tmp = (*lst)->next;
	i = 0;
	while (tmp)
	{
		ft_strcpy(str + i, (char *)(tmp->content));
		i += ft_strlen((char *)(tmp->content));
		tmp = tmp->next;
	}
	str[i] = '\0';
	write(1, str, ft_strlen(str));
	ft_strdel(&str);
	return (0);
}
