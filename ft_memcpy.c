/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:45:41 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/14 20:20:39 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*str;
	const char	*str2;

	str = dest;
	str2 = src;
	while (n)
	{
		*str = *str2;
		str++;
		str2++;
		n--;
	}
	return (dest);
}
