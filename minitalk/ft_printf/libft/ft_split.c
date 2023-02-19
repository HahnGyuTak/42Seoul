/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:52:02 by ghahn             #+#    #+#             */
/*   Updated: 2022/07/15 20:24:42 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (str[++i])
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			cnt++;
	return (cnt);
}

static int	check_free(char **ar, int idx)
{
	int	i;

	i = 0;
	if (!ar[idx])
	{
		while (ar[i])
		{
			free(ar[i]);
			i++;
		}
		free(ar);
		return (1);
	}
	else
		return (0);
}

static void	word_cpy(char **ar, char const *str, char c)
{
	int	idx;
	int	i;
	int	j;

	idx = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 1;
			while (str[i + j] != c && str[i + j])
				j++;
			ar[idx] = (char *)malloc(sizeof(char) * (j + 1));
			if (check_free(ar, idx))
				return ;
			ft_strlcpy(ar[idx], &str[i], j + 1);
			idx++;
			i += j;
		}
	}
	ar[idx] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (0);
	word_cpy(result, s, c);
	return (result);
}
