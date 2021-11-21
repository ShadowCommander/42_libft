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

char	*ft_strreplace(char *s1, char *s2)
{
	if (s1 != NULL)
		free(s1);
	return (s2);
}

static int	gnl_free_return(void **ptr)
{
	free(*ptr);
	*ptr == NULL;
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*sav[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t		size;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	size = 0;
	if (!sav[fd])
		sav[fd] = ft_strnew(0);
	while (!(tmp = ft_strchr(sav[fd], '\n')) &&
			(size = read(fd, buf, BUFFER_SIZE)) > 0)
		sav[fd] = ft_strreplace(sav[fd], ft_strnjoin(sav[fd], buf, size));
	if (size < 0)
		return (gnl_free_return(&sav[fd]);
	*line = ft_strsub(sav[fd], 0,
		tmp ? (size_t)(tmp - sav[fd]) : ft_strlen(sav[fd]));
	if (tmp != NULL)
		tmp++;
	sav[fd] = ft_strreplace(sav[fd], ft_strsub(tmp, 0, ft_strlen(tmp)));
	return (sav[fd] != NULL);
}
