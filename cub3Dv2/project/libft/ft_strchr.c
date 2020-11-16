/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:11:57 by idouidi               #+#    #+#             */
/*   Updated: 2019/10/15 17:11:37 by idouidi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == n)
			return ((char *)str + i);
		i++;
	}
	if (n == 0)
		return ((char *)str + i);
	return (0);
}
