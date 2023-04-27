#include "map.h"
#include "tools.h"
#include "main.h"
#include <fcntl.h>
#include <stdlib.h>

void	ft_map_display(int** map, t_map* params)
{
	int		i;
	int		j;
	int		k;
	char* str;

	i = -1;
	if (!(str = malloc(sizeof(*str) * params->width)))
		return;
	while (++i < params->height)
	{
		k = 0;
		j = -1;
		while (++j < params->width - 1)
		{
			if (map[i][j] == -1)
				str[k++] = params->square;
			else if (map[i][j] == 0)
				str[k++] = params->block;
			else
				str[k++] = params->dot;
		}
		str[k++] = '\n';
		str[k] = '\0';
		ft_putstr(str);
	}
}

int		main(int argc, char** argv)
{
	int				i;
	int				file;
	int**			 map;
	char*			grid;
	t_map	params;

	i = 0;
	while (i < argc || (argc == 1 && i == 0))
	{
		if (argc-- == 1)
			file = 0;
		else if ((file = open(argv[++i], O_RDONLY)) == -1)
			map_error();
		if (file != -1)
		{
			if ((grid = ft_read_file(file, &params))
				&& (map = convert_map(grid, &params)))
				ft_map_display(find_square(map, params), &params);
			else
				map_error();
		}
	}
	return (0);
}
