/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:51:27 by ghahn             #+#    #+#             */
/*   Updated: 2022/09/12 12:48:36 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_one_line(int fd, char *buff, char *next)
{
	int		byte;
	char	*tmp;

	byte = 1;
	while (byte)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
			return (0);
		else if (byte == 0)
			break ;
		if (next == NULL)
			next = ft_strdup("");
		buff[byte] = '\0';
		tmp = next;
		next = ft_strjoin(tmp, buff);
		if (next == NULL)
			return (NULL);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (next);
}

static char	*checking(char *s)
{
	int		i;
	char	*result;

	i = 0;
	while (!(s[i] == '\n' || s[i] == '\0'))
		i++;
	if (s[i] == '\0')
		return (0);
	result = ft_strdup(s + i + 1);
	if (result == NULL)
		return (NULL);
	if (result[0] == '\0')
	{
		free(result);
		return (NULL);
	}
	s[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*result;
	static char	*next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	result = read_one_line(fd, buff, next);
	free(buff);
	buff = NULL;
	if (result == NULL)
		return (NULL);
	next = checking(result);
	return (result);
}