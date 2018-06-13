/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:58:21 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/14 18:53:19 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMIZER_H
# define RANDOMIZER_H

# include <stdlib.h>
# include <time.h>
# include <unistd.h>

void		ft_usage(void);
int			ft_generate(int **arr, int len, int min, int max);
void		ft_mywrite(int *arr, int len, int k);

int			ft_atoi(const char *str);
void		ft_putnbr(int n);

#endif
