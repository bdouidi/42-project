/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:46:12 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/26 20:55:32 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	if (*needle == '\0')
		return ((char *)haystack);
	n = ft_strlen(needle);
	while (*haystack != '\0' && n <= len--)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, n) == 0)
			return ((char *)haystack);
		else
			haystack++;
	}
	return (NULL);
}
