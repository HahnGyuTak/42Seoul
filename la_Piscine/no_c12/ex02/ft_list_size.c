/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:52:13 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 21:57:54 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

int	ft_list_size(t_list *begin_list);
{
	t_list	*tmp;
	int		i;

	tmp = begin_list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
