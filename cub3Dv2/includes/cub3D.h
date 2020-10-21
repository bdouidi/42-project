/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:24:47 by dsy               #+#    #+#             */
/*   Updated: 2020/10/21 13:41:49 by othabchi         ###   ########.fr       */
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
	char		letter; // position de base
	double		pos_x; //position du joueur
	double		pos_y;	
	int			map_x;  // la case dans laquelle on se trouve
	int			map_y;
	double		dir_x;
	double		dir_y; 		//direction du joueur
	float		sp; // vitesse de deplacement
}               t_player;

typedef struct	s_ray
{
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		stepX;
	double		stepY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		perpWallDist;
	int			hit; // savoir si  on a touche un mur ou non;
	int			hit_side; // savoir dans quelle direction on a touche un mur (N, S, E, W);
	int			line_height; // hauteur de la ligne a dessiner sur l'ecran
}				t_ray;		

typedef	struct	s_square // Utilisé de base pour faire des test mais possibile de l'utiliser pour les sprites ("2" dans la map)
{
	int			width;
	int			height;
	int			imgx;
	int			imgy;
}				t_square;

typedef	struct	s_texture
{
    void 		*tex[6];
	char		*addr[6];
	int			width[6];
	int			height[6];
	int			bpp[6];//bits per pixel
	int			szl[6];//sizeline
	int			endian[6];
}				t_texture;

typedef	struct	s_sprite
{
	float		x;
	float		y;
	double		dist;
}				t_sprite;


typedef	struct	s_img
{
	void		*ptr[5];
    char		*addr[5];
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
	t_texture	texture;
	t_sprite	*spt;
    char		**map;
    char		*sprite;
    char		*north;
    char		*east;
    char		*south;
    char		*west;
    char		*tmp;
	char		*tmp1;
    char		*resolution;
    char		*floor;
    char		*ceiling;
	int			count_spt;
	int			mapX;
	int			mapY;
    int         f_color;
    int         c_color;
	int			save;
    long        res[2];
	double		cameraX;
	double		*rays;
	float		x;
	float		y;
}				t_data;

/***          			fucntion to pars                                    ***/
int			flags(char c);
int			is_flags(char *s, int i);
int			r_f_c(char *s);
char		*fill_str(char *s1, char *s2, int i, int j);
int			pars_info_map(t_data *d);
int			pars_map(t_data *d, int len);
int			pars_file(int fd, t_data *data);
void		adjust_map(t_data *d);
int			border(char *s);
char 		*noblank(char *s, int c);
char 		**noblank_2(char **s, int c, char *set);
/***                    function to set display                             ***/
int	        set_rfc(t_data *d);
/***                       function to display                         ***/
void		init_player(t_data *d);
int         cub3d(int fd, t_data *d);
void        window(t_data *d);
void		raycasting(t_data *d);
void		set_position(t_data *d);
void		my_mlx_pixel_put(t_data *d, int color);
void		drawfov(t_data *d);
void		drawline(t_data *d, double dir, int i, int color);
void		drawplayer(t_data *d, int y, int x);
void		which_dir(t_data *d, int keycode);
void 		which_dir2(t_data *d, int keycode, int x, int y);
void		drawsquare(t_data *d, int color);
void    	create_img(t_data *d, int i, int width, int height);
void		get_ray_size(t_data *d);
void		rotation(t_data *d, int keycode);
void		dda(t_data *d);
void    	draw_wall(t_data *d);
void		catch_sprite(t_data *d, int b);
void		dda_sprite(t_data *d);
void		check_dist(t_data *d,double dist);
void    	create_bitmap(t_data *d);
/***                                                                        ***/
void		leak(void *str);
void		leak_2(char **map);
void		clean(t_data *d);
int			create_trgb(int t, int r, int g, int b);
int			add_shade(t_data *d, int trgb, float dist);
int			get_r(int color);
int			get_g(int color);
int			get_b(int color);

#endif
