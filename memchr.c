/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:32:31 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/08 16:43:48 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *ptr_s;
	size_t		i;

	i = 0;
	ptr_s = s;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if ((unsigned char)c == ptr_s[i])
			return ((void*)ptr_s + i);
		i++;
	}
	return (NULL);
}
