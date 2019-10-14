/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:16:52 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/14 20:32:47 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*stock;
	int		i;

	i = 0;
	if (!(stock = (char *)malloc(sizeof(char) * (ft_strlen((char *)(s1) + 1)))))
		return (NULL);
	while (s1[i])
	{
		stock[i] = s1[i];
		i++;
	}
	stock[i] = '\0';
	return (stock);
}
