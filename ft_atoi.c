/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:21:49 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/15 14:08:01 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	long	stock;
	int		sign;

	i = 0;
	sign = 1;
	stock = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
				str[i] == '\n' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		stock = stock * 10 + str[i] - '0';
		i++;
	}
	return (stock * sign);
}
