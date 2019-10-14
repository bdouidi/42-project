/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:45:32 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/14 20:28:22 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;
	size_t		i;

	i = 0;
	ptr_dst = dst;
	ptr_src = src;
	while (i < len)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
