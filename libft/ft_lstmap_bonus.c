/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:22:27 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/28 16:38:49 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*list;
	t_list	*ptr;

	if (!lst || !f || !del || !(list = ft_lstnew(f(lst))))
		return (NULL);
	ptr = list;
	lst = lst->next;
	while (lst)
	{
		list->next = ft_lstnew(f(lst));
		if (!list->next)
		{
			while (ptr)
			{
				list = ptr->next;
				del(ptr->content);
				free(ptr);
				ptr = list;
			}
			return (NULL);
		}
		list = list->next;
		lst = lst->next;
	}
	return (ptr);
}
