/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <jtong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:01:11 by jtong             #+#    #+#             */
/*   Updated: 2021/11/23 09:00:29 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"
#include <stdlib.h>

void	ft_listdelete(t_llist **list, int malloced)
{
	if (list == NULL || *list == NULL)
		return ;
	ft_listclear(*list, malloced);
	free(*list);
	*list = NULL;
}
