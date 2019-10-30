/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:30:35 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/26 20:14:15 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	i = 0;
	d = (unsigned char*)dest;
	s = (unsigned const char *)src;
	while (i < n && (i == 0 || s[i - 1] != (unsigned char)c))
	{
		d[i] = s[i];
		i++;
	}
	if (i > 0 && s[i - 1] == (unsigned char)c)
		return (d + i);
	else
		return (NULL);
}
