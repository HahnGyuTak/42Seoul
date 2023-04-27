/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:20:04 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/15 22:30:46 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*newnode;
	t_list	*node;

	tmp = lst;
	node = NULL;
	if (!lst)
		return (NULL);
	while (1)
	{
		newnode = ft_lstnew(f(tmp->content));
		if (newnode == NULL)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&node, newnode);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (node);
}
