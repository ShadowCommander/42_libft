/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <jtong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:28:35 by jtong             #+#    #+#             */
/*   Updated: 2021/11/23 09:02:03 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	ft_getdigit(int i)
{
	if (i >= 0 && i <= 35)
		return ("0123456789abcdefghijklmnopqrstuvwxyz"[i]);
	return ('\0');
}

char	*ft_ulltoa_base(unsigned long long n, int base)
{
	unsigned long long	cpy;
	size_t				size;
	char				*str;

	if (base < 2 || base > 35)
		return (NULL);
	cpy = n;
	size = n == 0;
	while (cpy != 0)
	{
		cpy /= base;
		size++;
	}
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	while (size-- > 0)
	{
		str[size] = ft_getdigit(n % base);
		n /= base;
	}
	return (str);
}
