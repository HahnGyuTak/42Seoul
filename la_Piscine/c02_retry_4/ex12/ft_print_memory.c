/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:19:46 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 18:08:00 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

void	save_buffer(int num, int i, int *buf, int idx)
{
	if (num > i - 1)
		save_buffer(num / i, i, buf, idx + 1);
	buf[idx] = num % i;
}

void	print_hex(unsigned int num, int i, int cnt)
{
	int		buf[14 + 1];
	int		idx;
	char	*hex;

	hex = "0123456789abcde";
	idx = -1;
	while (idx++ < 14)
		buf[idx] = 0;
	save_buffer(num, i, buf, 0);
	idx = -1;
	while (idx++ < cnt)
		write(1, hex + buf[cnt - idx], 1);
}

void	print_char(char *c)
{
	if (*c >= ' ' && *c != 127)
		write(1, c, 1);
	else
		write(1, ".", 1);
}

void	print_me(void *st, unsigned int size, char *add)
{
	int	idx;

	print_hex((unsigned int)add, 16, 14);
	write(1, ": ", 2);
	idx = 0;
	while (idx++ < 16)
	{
		if (st + size <= (void *)(add + idx - 1))
			write(1, " ", 2);
		else
			print_hex((unsigned char)*(add + idx - 1), 16, 1);
		if (idx % 2 == 0)
			write(1, " ", 1);
	}
	idx = 0;
	while (idx++ < 16)
		if (st + size > (void *)(add + idx - 1))
			print_char((char *)add + idx - 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*add;

	add = (char *)addr;
	while ((void *)add < (addr + size))
	{
		print_me(addr, size, add);
		write(1, &"\n", 1);
		add += 16;
	}
	return (addr);
}
