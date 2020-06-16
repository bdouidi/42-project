/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:24:47 by dsy               #+#    #+#             */
/*   Updated: 2020/06/16 20:45:45 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../project/libft/libft.h"
# include "../mlx/mlx.h"

typedef struct  s_vars
{
	void	    *mlx;
	void	    *win;
}               t_vars;

typedef struct	s_player
{
	int         eye_height;	
	int         *pos;
	int         fov;
	int         wall_distance;
}               t_player;

typedef struct  s_data
{
    t_vars      vars;
    void		*img;
    // void		*imgtmp;
    char		*addr;
    int         line_length;
    int			bits_per_pixel;
    int 		endian;
    char		**map;
    char		*tmp;
    char		*resolution;
    long         res[2];
    char		*floor;
    int         f_color;
    char		*ceiling;
    int         c_color;
    char		*sprite;
    char		*north;
    char		*east;
    char		*south;
    char		*west;
}				t_data;

/***          			fucntion to pars                                    ***/
int			flags(char c);
int			is_flags(char *s, int i);
int			r_f_c(char *s);
char		*fill_str(char *s1, char *s2, int i, int j);
int			pars_info_map(t_data *d);
int			pars_map(char **map, int len);
int			pars_file(int fd, t_data *data);
void		adjust_map(t_data *d);
int			border(char *s);
char 		*noblank(char *s, int c);
char 		**noblank_2(char **s, int c, char *set);
/***                    function to set display                             ***/
int	        set_rfc(t_data *d);
/***                       function to display                         ***/
int         cub3d(int fd);
void        window(t_data *d);
/***                                                                        ***/
void		leak(char *str);
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
