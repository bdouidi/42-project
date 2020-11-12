/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:43 by dsy               #+#    #+#             */
/*   Updated: 2020/11/12 15:30:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstr;

	i = 0;
	// if (!s)
	// {
	// 	if (!(newstr = malloc(sizeof(char))))
	// 		return (NULL);
	// 	newstr[0] = 0;
	// 	return (newstr);
	// }
	if (!(newstr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > ft_strlen(s))
	{
		newstr[0] = '\0';
		return (newstr);
	}
	while (i < len && s[start])
	{
		newstr[i] = s[start++];
		i++;
	}
	newstr[i] = '\0';
	// printf("%s\n", newstr);
	return (newstr);
}
