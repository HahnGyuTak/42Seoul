#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	int		height;
	int		width;
	int		size;
	char	dot;
	char	block; 
	char	square;
}				t_map;

typedef struct	s_pos
{
	int x;
	int y;
	int point;
}				t_pos;

#endif
