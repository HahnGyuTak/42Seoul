#ifndef MAIN_H
# define MAIN_H

char* ft_read_file(int fd, t_map* params);
int** convert_map(char* grid, t_map* params);
int** find_square(int** map, t_map map_params);

#endif
