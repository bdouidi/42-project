/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:54:14 by idouidi               #+#    #+#             */
/*   Updated: 2019/10/15 17:16:44 by idouidi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (n == 0)
		i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == n)
			return ((char *)str + i);
		i--;
	}
	if (i == -1)
		return ((char*)NULL);
	return (0);
}
