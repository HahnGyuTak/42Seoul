/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:15:57 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 22:28:18 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	int		len;
	int		i;
	int		j;

	len = 0;
	tmp = *begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	i = 0;
	tmp = *begin_list;
	while (i++ < len - 1)
	{
		j = len - i;
		while (j--)
		{
			tmp->next = tmp->next->next;
			tmp->next->next = tmp;
			tmp = tmp->next;
		}
		tmp = *begin_list;
	}
}
