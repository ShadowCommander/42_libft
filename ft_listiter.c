/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:45:03 by jtong             #+#    #+#             */
/*   Updated: 2021/10/31 10:47:20 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_nodeiter(t_node *node, void (*f)(t_node *node))
{
	t_node	*next;

	if (!node || !(*f))
		return ;
	while (node)
	{
		next = node->next;
		(*f)(node);
		node = next;
	}
}
