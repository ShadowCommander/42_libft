/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:12:37 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 05:56:54 by jtong            ###   ########.fr       */
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
	v = (t_strtol){ptr, 0, 1, 0, 0, 0};
	while (ft_isspace(*v.s))
		v.s++;
	if (*v.s == '-' && ft_isalnum(v.s[1]))
		v.neg = -1;
	if ((*v.s == '-' || *v.s == '+') && ft_isalnum(v.s[1]))
		v.s++;
	v.cutoff = (LONG_MAX * v.neg) / base;
	v.cutlim = (LONG_MAX * v.neg) % base;
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
