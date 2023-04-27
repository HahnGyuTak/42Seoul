#include "tools.h"
#include <unistd.h>

void	map_error(void)
{
	write(2, "map error\n", 10);
}
