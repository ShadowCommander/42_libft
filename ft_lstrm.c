/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:06:54 by jtong             #+#    #+#             */
/*   Updated: 2021/10/21 13:06:05 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstrm(t_list **alst, t_list *elem)
{
	t_list	*list;
	t_list	*back;

	if (!alst || !*alst || !elem)
		return ;
	list = *alst;
	back = NULL;
	while (list && list != elem)
	{
		back = list;
		list = list->next;
	}
	if (list == elem)
	{
		if (back)
			back->next = list->next;
		else
			*alst = list->next;
		if (list->content)
			free(list->content);
		free(list);
	}
}
