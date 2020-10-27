/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:10:02 by dsy               #+#    #+#             */
/*   Updated: 2020/02/17 21:12:36 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*newstr;

	i = 0;
	newstr = NULL;
	if (!(newstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (i < ft_strlen(str))
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
