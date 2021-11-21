/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:34:05 by jtong             #+#    #+#             */
/*   Updated: 2021/10/21 11:46:04 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t s2_len)
{
	size_t	s1_len;
	char	*str;

	if (s2 == NULL)
		return (NULL);
	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	str = (char *)malloc(sizeof(*str) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	if (s1)
		ft_strcpy(str, s1);
	ft_strncpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}
