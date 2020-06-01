/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:45:41 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/26 20:06:19 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	unsigned const char	*srcs;

	i = 0;
	dst = (unsigned char*)dest;
	srcs = (unsigned const char*)src;
	if (dst == NULL && srcs == NULL)
		return (NULL);
	while (i < n)
	{
		dst[i] = srcs[i];
		i++;
	}
	return (dst);
}
