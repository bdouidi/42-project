/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:40:13 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/18 21:41:59 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if(lst && del)
	{
		while(lst)
		{
			if ((*lst)->next)
				del((*lst)->content);
			else
				(*lst) = NULL;
			free((*lst));
			(*lst) = NULL;
		}
	}
}
