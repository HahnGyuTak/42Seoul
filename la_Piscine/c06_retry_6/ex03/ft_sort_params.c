/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:32:34 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/30 10:49:09 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	char_print(char x)
{
	write(1, &x, 1);
}

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	if (s1[i] != '\0' && s2[i] == '\0')
		return (s1[i]);
	else if (s1[i] == '\0' && s2[i] != '\0')
		return (-1 * s2[i]);
	return (0);
}

void	print_str(char **s, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		while (*(s[i]))
			write(1, s[i]++, 1);
		i++;
		char_print('\n');
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	if (argc < 2)
		return (-1);
	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (str_cmp(argv[j], argv[j + 1]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	print_str(argv, argc);
	return (0);
}
