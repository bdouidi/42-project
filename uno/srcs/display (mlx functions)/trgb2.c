/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:52:33 by othabchi          #+#    #+#             */
/*   Updated: 2020/03/11 14:52:36 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_rgb(int trgb)
{
	return (trgb & 0x00FFFFFF);
}

int add_shade(double distance, int trgb)
{
	double nb;
	int r, g, b;

	nb = 1 - distance;
	printf("%x - %x - %x [%d]\n", get_r(trgb), get_g(trgb), get_b(trgb), get_t(trgb));
	r = get_r(trgb) * nb;
	g = get_g(trgb) * nb;
	b = get_b(trgb) * nb;
	printf("[%f]\n", nb);
    return(create_trgb(1, r, g, b));
}

int get_opposite(int trgb)
{
    return (trgb ^ 0xFFFFFF);
}