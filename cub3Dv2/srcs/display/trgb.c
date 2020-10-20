/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:22:40 by othabchi          #+#    #+#             */
/*   Updated: 2020/10/20 12:53:19 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h" 

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0x0000FF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	add_shade(t_data *d, int trgb, float dist)
{
	int t;
	int r;
	int g;
	int b;
	float shade;

	shade = 1 - dist / d->mapX;
	shade = pow(shade, 6);

	t = 1;
	r = (get_r(trgb) >> 16) * shade;
	g = (get_g(trgb) >> 8) * shade;
	b = get_b(trgb) * shade;
	// printf("%f -- %d,%x,%x,%x\n", shade, t, r, g, b);
	// t = (trgb & (0xFF << 24));
	// r = (trgb & (0xFF << 16)) * shade;
	// g = (trgb & (0xFF << 8)) * shade;
	// b = (trgb & 0xFF) * shade;
	// printf("%f -- %f,%f,%f,%f\n", shade, t, r, g, b);
	return(create_trgb(1, r, g, b));
}