/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:49:40 by jtong             #+#    #+#             */
/*   Updated: 2021/04/09 00:43:32 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

void	*ft_listclear(t_llist *list, int malloced)
{
	if (!list)
		return (NULL);
	while (list->start)
		ft_listfree(ft_listpop(list), malloced);
	list->end = NULL;
	list->length = 0;
	return (NULL);
}
