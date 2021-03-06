/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putull_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:58:55 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 04:17:06 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putull_fd(unsigned long long n, int fd)
{
	ssize_t	size;

	size = 0;
	if (n >= 10)
		size = ft_putull_fd(n / 10, fd);
	size += ft_putchar_fd((n % 10) + '0', fd);
	return (size);
}
