/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:40:13 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/28 16:29:36 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	if (!lst)
		return ;
	list = *lst;
	while (list != NULL)
	{
		temp = list;
		ft_lstdelone(temp, del);
		list = list->next;
	}
	*lst = NULL;
}
