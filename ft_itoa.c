/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:21:15 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/14 15:26:52 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digit(int n)
{
	int	stock;

	stock = 0;
	if (n < 0)
		n = n * -1;
	while (n)
	{
		n = n / 10;
		stock++;
	}
	return (stock);
}

void	ft_reverse_str(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	while (j < i)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j++;
		i--;
	}
}

void	ft_fill_str(char *str, int n, int sign)
{
	int		i;
	char	*ref;

	ref = "0123456789";
	i = 0;
	if (n < 0)
	{
		n = n * -1;
		str[ft_count_digit(n)] = '-';
	}
	while (n)
	{
		if (str[i] != '-')
		{
			str[i] = ref[n % 10];
			i++;
			n = n / 10;
		}
		else
			i++;
	}
	if (sign < 0)
		str[i + 1] = '\0';
	else
		str[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		stock;
	char	*tab;
	int		sign;

	stock = ft_count_digit(n);
	sign = 0;
	if (n < 0)
		sign = -1;
	if (!(tab = (char *)malloc(sizeof(char) * stock)))
		return (NULL);
	ft_fill_str(tab, n, sign);
	ft_reverse_str(tab);
	return (tab);
}
