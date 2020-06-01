/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowsetc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:40:46 by othabchi          #+#    #+#             */
/*   Updated: 2020/05/26 18:26:06 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    int     x = 0;
    int     y = 0;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while(y < 540)
    {
        while(x < res[0])
        {
            my_mlx_pixel_put(&img, x, y, create_trgb(1, tab_c[0], 255, 3));
         x++;
        }
        y++;
        x = 0;
    }
    while(y < 1080)
    {
        while(x < 1920)
        {
            my_mlx_pixel_put(&img, x, y, 0x00000DD);
         x++;
        }
        y++;
        x = 0;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

    mlx_loop(mlx);
    return 0;
}