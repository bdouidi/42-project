/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:45:32 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/15 19:44:12 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	char		*ptr_src;
	size_t		i;

	i = 0;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (src == dst)
		return (dst);
	if (src > dst)
	{
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			ptr_dst[i] = ptr_src[i];
	}
	return (dst);
}
