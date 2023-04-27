/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:48:30 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 21:57:35 by ghahn            ###   ########.fr       */
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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*p;

	p = ft_create_elem(data);
	if (*begin_list)
		p->next = *begin_list;
	*begin_list = p;
}
