/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:41:42 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 21:44:00 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memdup(void *ptr, size_t size)
{
	void	*dup;

	dup = malloc(sizeof(*dup) * size);
	ft_memcpy(dup, ptr, size);
	return (dup);
}

