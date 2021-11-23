/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <jtong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:53:05 by jtong             #+#    #+#             */
/*   Updated: 2021/11/23 09:01:23 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		**cpy_words(const char *str, char const *comp, char **output)
{
	int			whitespace;
	const char	*ptr;
	size_t		index;

	index = 0;
	whitespace = 1;
	while (*str)
	{
		while (*str && ft_strchr(comp, *str) != NULL)
		{
			whitespace = 1;
			str++;
		}
		ptr = str;
		while (*str && ft_strchr(comp, *str) == NULL)
		{
			whitespace = 0;
			str++;
		}
		if (whitespace == 0)
			if (!(output[index++] = ft_strsub(ptr, 0, str - ptr)))
				return (NULL);
	}
	return (output);
}

char			**ft_strsplit(char const *s, char const *comp)
{
	char	**output;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, comp);
	if (!(output = (char **)malloc(sizeof(*output) * (words + 1))))
		return (NULL);
	output[words] = NULL;
	cpy_words(s, comp, output);
	return (output);
}
