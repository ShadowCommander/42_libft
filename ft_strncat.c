/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <jtong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:05:15 by jtong             #+#    #+#             */
/*   Updated: 2021/11/23 09:21:47 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*o;
	size_t	i;

	o = s1 + ft_strlen(s1);
	if (n == 0)
		return (s1);
	i = 0;
	while (i < n && s2[i] != '\0')
	{
		o[i] = s2[i];
		i++;
	}
	o[i] = '\0';
	return (s1);
}
