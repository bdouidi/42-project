#include "../../includes/cub3D.h"

int	*set_resolution(t_data *d, int *r)
{
	char	*tmp_r;
	/*char	*tmp;
	int	i;

	i = 2*/;
	tmp_r = ft_epur(d->resolution);
	printf("%s\n", tmp_r);
	/*if (ft_isdigit(tmp_r[i]) == 1)
		while(tmp_r[i] && (ft_isdigit(tmp_r[i]) == 1))
			i++;
	tmp = ft_substr(tmp_r, 2, i - 1);
	r[0] = ft_atoi(tmp);
	tmp = ft_substr(tmp_r, i + 1, ft_strlen(tmp_r) - 1);
	r[1] = ft_atoi(tmp);*/
	return (r);
}

/*void	set_info_map(t_data *d)
{
	int	r[2];
	int	fc[3];

	r = set_resolution(d->resolution);
	fonction mlx pour res;
	fc = set_floor_ceiling(d->floor);
	fonction mlx pour floor;
	fc = set_floor_ceiling(d->ceiling);
	fonction mlx pour ceilling;
}*/
