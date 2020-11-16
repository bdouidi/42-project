/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:03:56 by idouidi               #+#    #+#             */
/*   Updated: 2019/10/20 15:18:22 by idouidi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memalloc(size_t n)
{
	void *mem;

	if (!(mem = malloc(sizeof(n))))
		return (NULL);
	ft_memset(mem, 0, n);
	return (mem);
}
