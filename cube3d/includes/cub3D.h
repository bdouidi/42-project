/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:24:47 by dsy               #+#    #+#             */
/*   Updated: 2020/07/07 18:46:40 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../project/libft/libft.h"
# include  <math.h>
# include "../mlx/mlx.h"

typedef struct  s_vars
{
	void	    *mlx;
	void	    *win;
}               t_vars;

typedef struct	s_player
{
	double      height;
	double		fov[2];
	char		letter;
	double		pos_x; //position du joueur
	double		pos_y;	
	int			map_x;  // la case dans laquelle on se trouve
	int			map_y;
	double		dir; 		//direction du joueur
	double		plan_x;		//le plan de camera du joueur
	double		plan_y;
	int         wall_distance;
}               t_player;

typedef struct	s_ray
{
	double		camera_x;
	double		dir;
	double		x[2];
	double		y[2];

	double		side_dist_x; // longueur du rayon de la position actuelle jusqu'a la prochaine intersection x ou y
	double		side_dist_y;

	double		delta_x; // longueur d'un rayon jusqu'a lq prochaine intersection x ou y;
	double		delta_y;
	double		perp_wall_dist;

	int			step_x; // dans quelle direction on se deplace ( 1 ou -1);
	int			step_y;

	int			hit; // savoir si  on a touche un mur ou non;
	int			hit_side; // savoir dans quelle direction on a touche un mur (N, S, E, W);

	int			line_height; // hauteur de la ligne a dessiner sur l'ecran
	int			drawstart;
	int			drawend;

}				t_ray;		

typedef	struct	s_square // Utilisé de base pour faire des test mais possibile de l'utiliser pour les sprites ("2" dans la map)
{
	int			width;
	int			height;
	int			imgx;
	int			imgy;
	// int			color;
}				t_square;

typedef	struct	 s_img
{
    void		*ptr[3];
    char		*addr[3];
    int         line_length;
    int			bits_per_pixel;
    int 		endian;
}				t_img;

typedef struct  s_data
{
	t_square	square;
    t_vars      vars;
	t_player	player;
	t_ray		ray;
	t_img		img;
    char		**map;
	int			mapX;
	int			mapY;
    char		*tmp;
    char		*resolution;
    long        res[2];
    char		*floor;
    int         f_color;
    char		*ceiling;
    int         c_color;
    char		*sprite;
    char		*north;
    char		*east;
    char		*south;
    char		*west;
	float		x;
	float		y;
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
void		init_player(t_data *d);
int         cub3d(int fd);
void        window(t_data *d);
void		raycasting(t_data *d);
void		set_position(t_data *d);
void		my_mlx_pixel_put(t_data *d, int color);
void		drawfov(t_data *d);
void		drawline(t_data *d, double dir, int i, int color);
void		drawplayer(t_data *d, int keycode);
void 		which_dir2(t_data *d, float spd, int keycode);
void		drawsquare(t_data *d, int color);
void    	create_img(t_data *d, int i, int width, int height);
/***                                                                        ***/
void		leak(char *str);
int			create_trgb(int t, int r, int g, int b);

#endif
