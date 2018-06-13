/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:59:09 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/04 18:59:25 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkmap(char *dst, char *src, int x, int y)
{
	int	i;
	int	j;
	int	k;
	int	b;

	i = 0;
	while ((dst[i] != '\0') && (b = 1))
	{
		j = -1;
		while ((dst[i + ++j] != '\n') && (b != 0))
		{
			b = 0;
			k = 0;
			while ((src[k] != '\0') && (b != 1))
				if (dst[i + j] == src[k++])
					b = 1;
		}
		if ((b == 0) || (j != x))
			return (0);
		i = i + j + 1;
		y--;
	}
	if (y != 0)
		return (0);
	return (1);
}
