/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:53:05 by exam              #+#    #+#             */
/*   Updated: 2021/11/25 09:39:30 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**cpy_words(const char *str, char c, char **output)
{
	int			detected;
	const char	*ptr;
	size_t		index;

	index = 0;
	detected = 1;
	while (*str)
	{
		if (*str && *str == c)
			detected = 1;
		while (*str && *str == c)
			str++;
		ptr = str;
		if (*str && *str != c)
			detected = 0;
		while (*str && *str != c)
			str++;
		if (detected != 0)
			continue ;
		output[index] = ft_strsub(ptr, 0, str - ptr);
		if (output[index] == NULL)
			return (NULL);
		index++;
	}
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	char	separator[2];
	size_t	words;

	if (s == NULL)
		return (NULL);
	separator[0] = c;
	separator[1] = '\0';
	words = ft_wordcount(s, separator);
	output = (char **)malloc(sizeof(*output) * (words + 1));
	if (output == NULL)
		return (NULL);
	output[words] = NULL;
	cpy_words(s, c, output);
	return (output);
}
