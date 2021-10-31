/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:49:54 by jtong             #+#    #+#             */
/*   Updated: 2021/10/31 10:53:11 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_listfiter(t_llist *list, t_node *node,
		void (*f)(t_llist *list, t_node *node))
{
	t_node	*next;

	if (list == NULL || node == NULL || (*f) == NULL)
		return ;
	while (node)
	{
		next = node->next;
		(*f)(list, node);
		node = next;
	}
}
