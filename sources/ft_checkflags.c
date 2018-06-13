/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:21:48 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/20 17:08:48 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checkflags(int argc, char **argv, t_stacks *a, t_fl *fl)
{
	if (!fl)
		return (0);
	ft_checkflagserr(argc, argv, a);
	if (!ft_strcmp(argv[1], "-vl")
		|| !ft_strcmp(argv[1], "-lv") || !ft_strcmp(argv[1], "-v"))
		fl->flv = 1;
	if (!ft_strcmp(argv[1], "-vl")
		|| !ft_strcmp(argv[1], "-lv") || !ft_strcmp(argv[1], "-l"))
		fl->fll = 1;
	if (!ft_strcmp(argv[1], "-v") && !ft_strcmp(argv[2], "-l"))
	{
		fl->fll = 1;
		return (2);
	}
	if (!ft_strcmp(argv[1], "-l") && !ft_strcmp(argv[2], "-v"))
	{
		fl->flv = 1;
		return (2);
	}
	if (fl->flv || fl->fll)
		return (1);
	return (0);
}

void	ft_checkflagserr(int argc, char **argv, t_stacks *a)
{
	if (((!ft_strcmp(argv[1], "-vl") || !ft_strcmp(argv[1], "-lv")
		|| !ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-l"))
		&& (argc < 3))
		|| ((!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-l"))
		&& (!ft_strcmp(argv[2], "-v") || !ft_strcmp(argv[2], "-l"))
		&& (argc < 4)))
		ft_error(a);
}
