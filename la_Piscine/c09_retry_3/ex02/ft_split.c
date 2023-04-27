/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:16:10 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/05 12:09:55 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*input_len(char *str, int *sp, int cnt_word)
{
	int	i;
	int	len;
	int	*len_array;

	i = 1;
	len = 0;
	len_array = (int *)malloc(sizeof(int) * (cnt_word + 1));
	len_array[0] = cnt_word;
	while (*str && i <= cnt_word)
	{
		if (sp[(unsigned char)*str] != 1 && sp[(unsigned char)*(str + 1)] == 1)
			len_array[i++] = len + 1;
		if (sp[(unsigned char)*str] == 1 && sp[(unsigned char)*(str + 1)] != 1)
			len = -1;
		len++;
		str++;
	}
	return (len_array);
}

int	*count_word(char *str, int *sp)
{
	int	i;
	int	cnt_word;
	int	*len;

	i = 0;
	cnt_word = 0;
	while (str[i])
	{
		while (sp[(unsigned char)str[i]] == 1 && str[i])
			i++;
		if (str[i] == '\0')
			break ;
		if (sp[(unsigned char)str[i]] != 1
			&& sp[(unsigned char)str[i + 1]] == 1)
			cnt_word++;
		i++;
	}
	len = input_len(str, sp, cnt_word);
	return (len);
}

void	init_checkbox(int *sp, char *sep)
{
	int	i;

	i = -1;
	while (++i < 256)
		sp[i] = 0;
	i = 0;
	while (sep[i])
		sp[(unsigned char)sep[i++]] = 1;
	sp[0] = 1;
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		*cnt_word;
	char	**result;
	int		sp[256];

	init_checkbox(sp, charset);
	cnt_word = count_word(str, sp);
	result = (char **)malloc(sizeof(char *) * (cnt_word[0] + 1));
	i = 0;
	while (i < cnt_word[0] && *str)
	{
		while (sp[(unsigned char)*str] == 1)
			str++;
		result[i] = (char *)malloc(sizeof(char) * (cnt_word[i + 1] + 1));
		result[i] = ft_strncpy(result[i], str, cnt_word[i + 1]);
		result[i][cnt_word[i + 1]] = '\0';
		str += cnt_word[i++ + 1];
	}
	result[i] = 0;
	return (result);
}
/*
int main(void)
{
	printf("======ex05======\n");
	char charset[10] = "gR";
	char str[100] = "bapC4PWeVj9f0IeUOEvosNsuPDCz0UxRjMlIEXXf";
	char **strs = ft_split(str, charset);
	int i = 0;
	while (strs[i] != NULL)
	{
		printf("%s\n", strs[i]);
		i++;
	}
}*/
