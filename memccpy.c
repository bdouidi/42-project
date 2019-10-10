/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:30:35 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/08 14:30:11 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char	*stock;
	char		*stock2;
	size_t		i;

	stock = src;
	stock2 = dest;
	i = 0;
	while (i < n)
	{
		stock2[i] = stock[i];
		if ((unsigned char)c == stock[i])
			return (stock2 + i + 1);
		i++;
	}
	return (NULL);
}
