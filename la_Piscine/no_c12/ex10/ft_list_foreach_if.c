/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 03:03:42 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/08 03:08:29 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp)
	{
		if (cmp(tmp->data, data_ref) == 0)
			(*f)(tmp->data);
		tmp = tmp->next;
	}
}
