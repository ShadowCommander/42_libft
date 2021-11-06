/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 22:36:57 by jtong             #+#    #+#             */
/*   Updated: 2021/11/04 09:28:33 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		size;
	int		neg;
	char	*str;

	neg = n < 0;
	size = ft_intlen(n) + neg;
	str = ft_strnew(sizeof(*str) * (size + 1 + neg));
	if (str == NULL)
		return (NULL);
	if (neg)
		str[0] = '-';
	while (size-- > 0)
	{
		if (neg)
			str[size + neg] = (-1 * (n % 10)) + '0';
		else
			str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
