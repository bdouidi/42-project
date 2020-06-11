#include "../../includes/cub3D.h"

int	cub3d(int fd)
{
	t_data 	d;
	//int	r[2];

	if (fd < 0 || pars_file(fd, d) == -1)
		return (-1);
	printf("%s\n", d.resolution);
	//set_resolution(&d, r);
	//printf("%s\n", ft_epur(d.resolution));
	//printf("%d %d\n", r[0], r[1]);
	return (0);
}
