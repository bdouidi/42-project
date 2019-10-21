/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:37:52 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/21 19:57:06 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	if (!(new_elem = malloc(sizeof(new_elem))))
		return (NULL);
	if (content == NULL)
		new_elem->content = NULL;
	else
	{
		if (!(new_elem->content = (void *)malloc(sizeof(content))))
		{
			free(new_elem);
			return (NULL);
		}
		ft_memcpy(new_elem->content, content, ft_strlen(content));
	}
	new_elem->next = NULL;
	return (new_elem);
}
