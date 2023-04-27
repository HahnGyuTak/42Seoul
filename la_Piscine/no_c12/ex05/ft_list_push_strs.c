/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:27:27 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 21:57:13 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_list	*ft_create_elem(char *data)
{
	t _list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode)
	{
		(char*)(newnode->data) = data;
		newnode->next = NULL;
	}
	return (newnode);
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*result;
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = ft_create_elem(*str++);
	result = tmp;
	while (i++ < size)
	{
		tmp = ft_create_elem(*str++);
		tmp->next = result;
		result = tmp;
	}
	return (result);
}
