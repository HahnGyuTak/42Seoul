/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:11:02 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/18 15:26:10 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	while (1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
		if (*lst == NULL)
			break ;
	}
	*lst = NULL;
}
