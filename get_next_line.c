/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:35:10 by jtong             #+#    #+#             */
/*   Updated: 2021/04/04 21:58:59 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

static char	*ft_strreplace(char *s1, char *s2)
{
	if (s1 != NULL)
		free(s1);
	return (s2);
}

static int	gnl_init(const int fd, char **line, char *sav[])
{
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (sav[fd] == NULL)
		sav[fd] = ft_strnew(0);
	if (sav[fd] == NULL)
		return (-1);
	return (0);
}

static int	gnl_read(const int fd, char **tmp, char **sav)
{
	ssize_t		size;
	char		buf[BUFFER_SIZE + 1];

	size = 0;
	*tmp = ft_strchr(*sav, '\n');
	if (*tmp == NULL)
		size = read(fd, buf, BUFFER_SIZE);
	while (*tmp == NULL && size > 0)
	{
		*sav = ft_strreplace(*sav, ft_strnjoin(*sav, buf, size));
		*tmp = ft_strchr(*sav, '\n');
		if (*tmp == NULL)
			size = read(fd, buf, BUFFER_SIZE);
	}
	if (size < 0)
	{
		free(sav[fd]);
		sav[fd] = NULL;
		return (-1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*sav[FD_MAX];
	char		*tmp;

	if (gnl_init(fd, line, sav) == -1)
		return (-1);
	if (gnl_read(fd, &tmp, &sav[fd]) == -1)
		return (-1);
	if (tmp != NULL)
		*line = ft_strsub(sav[fd], 0, (size_t)(tmp - sav[fd]));
	else
		*line = ft_strsub(sav[fd], 0, ft_strlen(sav[fd]));
	if (tmp != NULL)
	{
		tmp++;
		sav[fd] = ft_strreplace(sav[fd], ft_strsub(tmp, 0, ft_strlen(tmp)));
	}
	else
		sav[fd] = NULL;
	return (sav[fd] != NULL);
}
