/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:15:31 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/16 18:46:40 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (n)
	{
		if ((unsigned const char *)s1 != (unsigned const char *)s2)
			return ((unsigned const char *)s1 - (unsigned const char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
