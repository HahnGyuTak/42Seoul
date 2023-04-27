/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:12:11 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 22:15:23 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list	*begin_list, unsigned int nbr)
{
	t_list	*tmp;

	tmp = begin_list;
	while (nbr-- > 1)
		tmp = tmp->next;
	return (tmp);
}
