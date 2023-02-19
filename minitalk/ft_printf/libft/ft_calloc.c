/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:15:35 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/10 12:22:14 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = NULL;
	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	tmp = malloc(count * size);
	if (tmp)
		ft_bzero(tmp, count * size);
	return (tmp);
}
