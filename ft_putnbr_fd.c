/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:43:30 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/24 15:12:59 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	res;

	res = (long)n;
	if (res < 0)
	{
		ft_putchar_fd('-', fd);
		res = (res * -1);
	}
	if (res >= 0 && res <= 9)
		ft_putchar_fd(res + '0', fd);
	else
	{
		ft_putnbr_fd(res / 10, fd);
		ft_putnbr_fd(res % 10, fd);
	}
}
