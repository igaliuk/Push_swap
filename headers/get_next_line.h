/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:27:48 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/15 15:10:03 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../sources/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 5

int					get_next_line(const int fd, char **line);

#endif
