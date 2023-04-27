/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:09:23 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 21:58:22 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_list.h"

static t_list	*ft_create_elem(void *data)
{
	t _list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode)
	{
		newnode->data = data;
		newnode->next = NULL;
	}
	return (newnode);
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
