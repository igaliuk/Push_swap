/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:44:42 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/23 15:05:53 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "randomizer.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;

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
		if (res > 1000000 || str[i] < '0' || str[i] > '9')
		{
			write(1, "\e[1;35mincorrect input\n\e[0m", 27);
			exit(0);
		}
		i++;
	}
	return (res * sign);
}

int		ft_generate(int **arr, int len, int min, int max)
{
	int		i;
	int		j;

	if (max - min + 1 < len)
		return (-1);
	srand(time(NULL));
	(*arr)[0] = min + rand() % (max - min + 1);
	i = 1;
	while (i < len)
	{
		(*arr)[i] = min + rand() % (max - min + 1);
		j = 0;
		while (j < i)
		{
			if ((*arr)[j] == (*arr)[i])
			{
				i--;
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if ((n / 10) > 0)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_mywrite(int *arr, int len, int k)
{
	int		i;

	if (k == 1)
	{
		write(1, "usage: ./randomizer \e[1mn min max\e[0m\n", 38);
		write(1,
			"       [\e[1mn\e[0m   - number of numbers (0..1000000)]\n", 54);
		write(1,
			"       [\e[1mmin\e[0m - min of numbers (>= -1000000)]\n", 52);
		write(1,
			"       [\e[1mmax\e[0m - max of numbers (<= 1000000)]\n", 51);
	}
	if (k == 2)
	{
		i = 0;
		while (i < len - 1)
		{
			ft_putnbr(arr[i++]);
			write(1, " ", 1);
		}
		ft_putnbr(arr[i]);
	}
}

int		main(int argc, char **argv)
{
	int		*arr;
	int		len;

	if (argc == 1)
		ft_mywrite(NULL, 0, 1);
	else if (argc != 4)
		write(1, "\e[1;35mincorrect input\n\e[0m", 27);
	else
	{
		len = ft_atoi(argv[1]);
		if (!(arr = (int *)malloc(sizeof(int) * len)))
		{
			write(1, "\e[1;31merror\n\e[0m", 17);
			exit(0);
		}
		if (ft_generate(&arr, len, ft_atoi(argv[2]), ft_atoi(argv[3])) == -1)
			write(1, "\e[1;35mincorrect input\n\e[0m", 27);
		else
			ft_mywrite(arr, len, 2);
		free(arr);
		arr = NULL;
	}
	return (0);
}
