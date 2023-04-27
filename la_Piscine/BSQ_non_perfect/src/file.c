#include <unistd.h>
#include <stdlib.h>
#include "tools.h"
#include "map.h"
#define BUFF_SIZE 8192

char* ft_read_until(int fd, char c)
{
	char* buff;
	char* tmp;
	char* input;
	int		len;

	if (!(buff = malloc(sizeof(*buff))))
		return (0);
	if (!(input = malloc(sizeof(*input))))
		return (0);
	input[0] = '\0';
	len = 0;
	while (read(fd, buff, 1) > 0 && *buff != c)
	{
		len++;
		tmp = input;
		if (!(input = malloc(sizeof(*input) * (++len + 1))))
			return (0);
		input[0] = '\0';
		ft_strcat(input, tmp);
		ft_strncat(input, buff, 1);
		free(tmp);
	}
	input[len] = '\0';
	return (input);
}

int		ft_complete_map(t_map* map, char* params)
{
	int		i;
	int		len;
	char* lines;

	len = 0;
	while (params[len] != '\0')
		len++;
	if (!(lines = (char*)malloc(sizeof(char) * (len - 3 + 1))))
		return (0);
	i = 0;
	while (params[i + 3] != '\0')
	{
		lines[i] = params[i];
		i++;
	}
	lines[i] = '\0';
	map->height = ft_atoi(lines);
	map->dot = params[i++];
	map->block = params[i++];
	map->square = params[i];
	return (1);
}

char* ft_read_file(int fd, t_map* map)
{
	int		i;
	char* tmp;
	char* str;

	ft_complete_map(map, ft_read_until(fd, '\n'));
	tmp = ft_read_until(fd, '\n');
	map->width = ft_strlen(tmp) + 1;
	if (map->height <= 0)
		return (0);
	if (!(str = (char*)malloc(sizeof(*str) * (map->height * map->width))))
		return (0);
	str[0] = '\0';
	ft_strcat(str, tmp);
	str[map->width - 1] = '\n';
	str += map->width;
	if ((i = read(fd, str, (map->height - 1) * map->width)) < 0)
		return (0);
	if (i != (map->height - 1) * map->width)
		return (0);
	str -= map->width;
	if (read(fd, tmp, 1) > 0 || str[map->height * map->width - 1] != '\n')
		return (0);
	str[map->height * map->width - 1] = '\0';
	return (str);
}
