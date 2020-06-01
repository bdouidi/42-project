/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:22:27 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/21 21:57:42 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	int	stock;
	t_list	*ptr;

	stock = ft_lstsize(lst);
	if (lst && f)
	{
		if (!(ptr = ft_lstnew(lst->content)))
			return NULL;
		while (ptr)
		{
			if(ptr->content)
			{
				ptr->next = ft_lstnew(f(ptr->content));
				ptr = ptr->next;
			}
			else
			{
				del(ptr->content);
				free (ptr);
				ptr = NULL;
			}
		}
		return (ptr);
	}
	return NULL;
}
