/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:06:11 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/06 17:13:59 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	ft_putchar(char x)
{
	write(1, &x, 1);
}

static void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

void	read_file(char *fpath)
{
	int		f;
	int		size;
	char	buffer[1025];

	f = open(fpath, O_RDONLY);
	if (f == -1)
		write(1, "Cannot read file.\n", 18);
	else
	{
		size = read(f, buffer, 1024);
		while (size != 0)
		{
			ft_putstr(buffer);
			size = read(f, buffer, 1024);
		}
	}
}

int	main(int argc, char *argv[])
{
	if (argc >= 3)
		write(1, "Too many arguments.\n", 20);
	else if (argc == 1)
		write(1, "File name missing.\n", 19);
	else
		read_file(argv[1]);
}	
