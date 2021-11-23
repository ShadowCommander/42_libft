/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <jtong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:12:37 by jtong             #+#    #+#             */
/*   Updated: 2021/11/23 09:18:33 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_ctoi(int c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_isupper(c))
		return (c - ('A' - 10));
	else if (ft_islower(c))
		return (c - ('a' - 10));
	return (c);
}

long	ft_strtol(const char *ptr, char **endptr, int base)
{
	t_strtol	v;

	if (base <= 1 || base > 16)
		return (0);
	v.s = ptr;
	while (ft_isspace(*v.s))
		v.s++;
	v.neg = 1;
	if (*v.s == '-')
		v.neg = -1;
	v.s += (*v.s == '-' || *v.s == '+');
	v.cutoff = (LONG_MAX * v.neg) / base;
	v.cutlim = (LONG_MAX * v.neg) % base;
	v.acc = 0;
	while (ft_isalnum(*v.s) && ft_ctoi(*v.s) < base)
	{
		v.c = ft_ctoi(*v.s);
		if (v.acc >= v.cutoff * v.neg && v.c > v.cutlim + (v.neg == -1))
			return (LONG_MAX * v.neg);
		v.acc = (v.acc * base) + (v.c * v.neg);
		v.s++;
	}
	if (endptr)
		*endptr = (char *)(v.s);
	return (v.acc);
}
