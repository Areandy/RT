/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:40:08 by mlavreni          #+#    #+#             */
/*   Updated: 2018/11/06 09:40:09 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100
# define ERROR(x, y) if(x < 0 || !y) return (-1);
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>

int		get_next_line(const int fd, char **line);

#endif
