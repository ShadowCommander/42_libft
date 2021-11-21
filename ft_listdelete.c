/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:01:11 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 22:04:15 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"

void	ft_listdelete(t_llist **list, int malloced)
{
	ft_listclear(*list, malloced);
	free(*list);
	*list = NULL;
}
