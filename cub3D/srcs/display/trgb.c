/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:30:41 by othabchi          #+#    #+#             */
/*   Updated: 2020/08/07 11:55:25 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		get_r(int color)
{
	return (color & (0xFF << 16));
}

int		get_g(int color)
{
	return (color & (0xFF << 8));
}

int		get_b(int color)
{
	return (color & 0xFF);
}