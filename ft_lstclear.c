/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:40:13 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/21 19:56:32 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*stock;

	l = *lst;
	stock = NULL;
	if (lst && del)
	{
		while (l)
		{
			if (l->next)
				stock = l->next;
			else
				stock = NULL;
			del(l->content);
			free(l);
			l = stock;
		}
	}
	*lst = NULL;
}
