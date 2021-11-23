/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <jtong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:50:17 by jtong             #+#    #+#             */
/*   Updated: 2021/11/23 09:24:02 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *str, char const *separators)
{
	int		whitespace;
	size_t	words;

	whitespace = 1;
	words = 0;
	while (*str)
	{
		while (*str && ft_strchr(separators, *str) != NULL)
		{
			whitespace = 1;
			str++;
		}
		while (*str && ft_strchr(separators, *str) == NULL)
		{
			whitespace = 0;
			str++;
		}
		if (whitespace == 0)
			words++;
	}
	return (words);
}
