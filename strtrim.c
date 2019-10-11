/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 03:04:37 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/11 04:42:18 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int		count_set(char const *s1, char const *set)
{
	int	i;
	int j;
	int	stock;
	int lenght;

	i = 0;
	j = 0;
	stock = 0;
		while (s1[i])
		{
			while (set[j])
			{

			}
		}
	}
	//printf("%d\n", stock);
	return (stock);

}

/*char	*ft_strtrim(char const *s1, char const *set)
{

}
*/

int main ()
{

printf("%d\n", count_set("salut", "slt"));
return 0;
}
