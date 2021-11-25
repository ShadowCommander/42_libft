/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <jtong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 19:11:49 by jtong             #+#    #+#             */
/*   Updated: 2021/11/25 09:41:05 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_node	*ft_listfind(t_llist *list, int (*f)(t_node *, void *, size_t),
			void *content, size_t size)
{
	t_node	*node;

	node = list->start;
	while (node)
	{
		if ((*f)(node, content, size))
			return (node);
		node = node->next;
	}
	return (NULL);
}
