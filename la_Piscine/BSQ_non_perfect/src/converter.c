#include "map.h"
#include <stdlib.h>

int** convert_map(char* grid, t_map* map)
{
	int j;
	int k;
	int** data;

	j = -1;
	k = 0;
	if (!(data = (int**)malloc(sizeof(int*) * map->height)) ||
		!(data[++j] = (int*)malloc(sizeof(int) * map->width)))
		return (0);
	while (*grid != '\0')
	{
		if (*grid == '\n')
		{
			if (((k != map->width - 1)) ||
				!(data[++j] = (int*)malloc(sizeof(**data) * map->width)))
				return (0);
			k = 0;
		}
		if (*grid == map->dot)
			data[j][k++] = -1;
		if (*grid++ == map->block)
			data[j][k++] = 0;
	}
	return (data);
}
