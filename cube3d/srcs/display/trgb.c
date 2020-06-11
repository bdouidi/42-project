/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:30:41 by othabchi          #+#    #+#             */
/*   Updated: 2020/06/11 14:21:48 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		get_t(int trgb)
{
	return ((trgb & 0xFF000000) >> 24);
}

int		get_r(int trgb)
{
	return ((trgb & 0xFF0000) >> 16);
}

int		get_g(int trgb)
{
	return ((trgb & 0xFF00) >> 8);
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

int		get_rgb(int trgb)
{
	return (trgb & 0x00FFFFFF);
}

// int add_shade(double distance, int trgb)
// {
// 	double nb;
// 	int r, g, b;

// 	nb = 1 - distance;
// 	r = get_r(trgb) * nb;
// 	g = get_g(trgb) * nb;
// 	b = get_b(trgb) * nb;
//     return(create_trgb(1, r, g, b));
// }

// int get_opposite(int trgb)
// {
//     return (trgb ^ 0xFFFFFF);
// }

// int main()
// {
// 	int trgb = create_trgb(1, 123, 100, 85);
// 	int trgb2 = add_shade(.25, trgb);

// 	printf("%x\n", trgb);
// 	printf("%d\n", get_r(trgb));
// 	printf("%d\n", get_g(trgb));
// 	printf("%d\n", get_b(trgb));

// 	// printf("%x\n", get_opposite(trgb));

// 	// printf("%x - %x - %x [%d]\n", get_r(trgb2), get_g(trgb2), get_b(trgb2), get_t(trgb2));
//     return 0;
// }