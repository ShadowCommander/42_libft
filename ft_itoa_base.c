/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:32:37 by jtong             #+#    #+#             */
/*   Updated: 2018/11/14 22:31:20 by jtong            ###   ########.fr       */
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

char	*ft_itoa_base(int n, int base)
{
	int		size;
	int		offset;
	char	*str;

	if (base < 2 || base > 35)
		return (NULL);
	offset = n;
	size = (n == 0) + (base == 10 && n < 0);
	while (offset != 0)
	{
		offset /= base;
		size++;
	}
	offset = (base == 10 && n < 0);
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	if (n < 0 && base == 10)
		str[0] = '-';
	while (size-- > offset)
	{
		str[size] = ft_getdigit(ft_abs(n % base));
		n /= base;
	}
	return (str);
}
