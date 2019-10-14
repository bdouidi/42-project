/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:13:40 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/14 15:49:47 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*stock;
	unsigned int		i;

	if (!s)
		return (NULL);
	i = 0;
	stock = ft_strdup(s);
	while (stock[i])
	{
		stock[i] = f(i, stock[i]);
		i++;
	}
	return (stock);
}
