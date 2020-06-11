/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:30:41 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/11 15:53:06 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int get_opposite(int trgb)
{
    return (trgb ^ 0xFFFFFF);
}

// int add_shade(double distance, int trgb)
// {
// 	double nb;
// 	int r, g, b;

// 	nb = 1 - distance;
// 	r = get_r(trgb) * nb;
// 	g = get_g(trgb) * nb;
// 	b = get_b(trgb) * nb;
//  return(create_trgb(1, r, g, b));
// }
