/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:15:57 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 21:58:36 by ghahn            ###   ########.fr       */
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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*newnode;
	t_list	*tmp;

	newnode = ft_create_elem(data);
	if (*begin_list == NULL)
		*begin_list = newnode;
	else
	{
		tmp = begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newnode;
	}
}
