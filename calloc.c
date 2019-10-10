/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:57:43 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/10 21:16:11 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size)
{
	char	*stock;
	int		i;

	i = 0;
	if (count == NULL || size == NULL)
		return NULL;
	if (!(stock = (char *)malloc(count * size)))
		return NULL;
	while (stock[i])
	{
		stock[i] = 0;
		i++;
	}
	return (stock);
}
