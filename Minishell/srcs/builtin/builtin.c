/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:05:48 by user42            #+#    #+#             */
/*   Updated: 2021/07/07 15:48:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(t_data *d, char **expression)
{
	int	i;

	i = 0;
	while (d->builtin_str[i])
	{
		if (ft_strcmp(expression[0], d->builtin_str[i]) == 0)
			break ;
		i++;
	}
	if (i == 7)
		return (-1);
	return (i);
}

int	builtin(t_data *d, char **expression)
{
	int	index;

	index = is_builtin(d, expression);
	if (index != -1)
	{
		d->is_builtin = 1;
		if (redirection(d, expression) == -1)
			return (-2);
		d->builtin_func[index](d, expression);
	}
	return (index);
}
