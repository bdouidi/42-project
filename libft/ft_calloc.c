/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:57:43 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/23 17:59:03 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*stock;
	int		i;

	i = 0;
	if (!(stock = (char *)malloc(count * size)))
		return (NULL);
	ft_bzero(stock, count);
	return (stock);
}
