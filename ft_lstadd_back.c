/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:54:05 by idouidi           #+#    #+#             */
/*   Updated: 2019/10/18 19:35:04 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst && (*alst) && new)
	{
		if ((*alst) == NULL)
			(*alst) = new;
		else
		{
			while ((*alst)->next)
				(*alst) = (*alst)->next;
			(*alst)->next = new;
		}
	}
}
