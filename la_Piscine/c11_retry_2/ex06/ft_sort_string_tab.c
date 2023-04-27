/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:55:42 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 00:58:38 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;
	int		cnt;

	cnt = 0;
	while (tab[cnt])
		cnt++;
	i = 0;
	while (i < cnt - 1)
	{
		j = 0;
		while (j < cnt - 1)
		{
			if (str_cmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
