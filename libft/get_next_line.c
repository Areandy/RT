/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:52:05 by mlavreni          #+#    #+#             */
/*   Updated: 2018/11/12 14:52:10 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		it_is_the_end(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static char		*trashless_strsub(char *s, unsigned int start,
	size_t len, char *trash)
{
	char	*tmp;

	tmp = ft_strsub(s, start, len);
	free(trash);
	return (tmp);
}

static int		apply_magic(char **temp, char **line, int fd)
{
	int len;

	len = it_is_the_end(temp[fd]);
	if (temp[fd][len] == '\n')
	{
		*line = ft_strsub(temp[fd], 0, len);
		temp[fd] = trashless_strsub(temp[fd], len + 1,
		ft_strlen(temp[fd]) - len, temp[fd]);
		return (1);
	}
	*line = ft_strdup(temp[fd]);
	ft_strdel(&temp[fd]);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char *temp[10000];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			rat;

	ERROR(fd, line);
	while ((rat = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rat] = '\0';
		if (!temp[fd])
			temp[fd] = ft_strnew(1);
		tmp = temp[fd];
		temp[fd] = ft_strjoin(temp[fd], buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	ERROR(rat, line);
	if (rat == 0 && (!temp[fd] || !temp[fd][0]))
		return (0);
	return (apply_magic(temp, line, fd));
}
