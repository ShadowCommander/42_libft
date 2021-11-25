/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <jtong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:53:05 by jtong             #+#    #+#             */
/*   Updated: 2021/11/25 09:39:57 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**cpy_words(const char *str, char const *separators, char **output)
{
	int			detected;
	const char	*ptr;
	size_t		index;

	index = 0;
	detected = 1;
	while (*str)
	{
		if (*str && ft_strchr(separators, *str) != NULL)
			detected = 1;
		while (*str && ft_strchr(separators, *str) != NULL)
			str++;
		ptr = str;
		if (*str && ft_strchr(separators, *str) == NULL)
			detected = 0;
		while (*str && ft_strchr(separators, *str) == NULL)
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

char	**ft_strsplit(char const *s, char const *separators)
{
	char	**output;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = ft_wordcount(s, separators);
	output = (char **)malloc(sizeof(*output) * (words + 1));
	if (output == NULL)
		return (NULL);
	output[words] = NULL;
	cpy_words(s, separators, output);
	return (output);
}
