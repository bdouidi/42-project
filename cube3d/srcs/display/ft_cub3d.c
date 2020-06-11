#include "../../includes/cub3D.h"

int	cub3d(int fd)
{
	t_data 	d;
	int	r[2];

	if (fd < 0 || pars_file(fd) == -1)
		return (-1);
	r = set_resolution(&d);
	return (0);
}
