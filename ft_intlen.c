/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:28:11 by jtong             #+#    #+#             */
/*   Updated: 2021/11/04 09:29:51 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(int n)
{
	int	len;
	
	len = n < 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

