/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:24:47 by dsy               #+#    #+#             */
/*   Updated: 2020/05/27 16:09:40 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../project/libft/libft.h"
# include "../mlx/mlx.h"

typedef struct  s_data
{
    char	**map;
    void        *img;
    char        *addr;
    char	*tmp;
    char        *resolution;
    char        *floor;
    char        *ceiling;
    char	*sprite;
    char	*north;
    char	*east;
    char	*south;
    char	*west;
    int         bits_per_pixel;
    int         endian;
    
}		t_data;

typedef struct	s_player
{
	int         eye_height;	
	int         *pos;
    	int         fov;
    	int         wall_distance;
}               t_player;

int		ft_pars(char **av);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
