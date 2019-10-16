/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:45:41 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/16 17:30:12 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;

	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (n)
	{
		*str = *str2;
		str++;
		str2++;
		n--;
	}
	return (dest);
}
