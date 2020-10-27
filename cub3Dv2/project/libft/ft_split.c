/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:49:43 by idouidi           #+#    #+#             */
/*   Updated: 2020/05/30 22:28:11 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



char				**ft_clear_splitted(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, const char *delimiters)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && ft_strchr(delimiters, s[i]))
		i++;
	while (s[i])
	{
		if (ft_strchr(delimiters, s[i]))
		{
			nb_strs++;
			while (s[i] && ft_strchr(delimiters, s[i]))
				i++;
			continue ;
		}
		i++;
	}
	if (!ft_strchr(delimiters, s[i - 1]))
		nb_strs++;
	return (nb_strs);
}

static void			ft_get_next_str(char **next_str, unsigned int *next_str_len,
					const char *delimiters)
{
	unsigned int i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && ft_strchr(delimiters, **next_str))
		(*next_str)++;
	while ((*next_str)[i])
	{
		if (ft_strchr(delimiters, (*next_str)[i]))
			return ;
		(*next_str_len)++;
		i++;
	}
}

char				**ft_split(char *s,  char *delimiters)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	nb_strs = ft_get_nb_strs(s, delimiters);
	if (!(tab = malloc(sizeof(char *) * (nb_strs + 1))))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, delimiters);
		if (!(tab[i] = malloc(sizeof(char) * (next_str_len + 1))))
			return (ft_clear_splitted(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

// static int	get_words(char *str, char c)
// {
// 	int		i;
// 	int		word;
// 	int		wflag;

// 	i = 0;
// 	word = 0;
// 	wflag = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 		{
// 			if (!wflag)
// 			{
// 				wflag = 1;
// 				word++;
// 			}
// 		}
// 		else
// 			wflag = 0;
// 		i++;
// 	}
// 	return (word);
// }

// static char	*cut_word(char *str, char c)
// {
// 	int		i;
// 	int		j;
// 	char	*str_return;

// 	i = 0;
// 	while (str[i] && str[i] != c)
// 		i++;
// 	j = i;
// 	i = 0;
// 	if ((str_return = (char*)malloc(sizeof(char) * j + 1)) == NULL)
// 		return (NULL);
// 	while (i < j)
// 	{
// 		str_return[i] = str[i];
// 		i++;
// 	}
// 	str_return[i] = '\0';
// 	return (str_return);
// }

// static char	*get_word(char *str, int w, char c)
// {
// 	int		i;
// 	int		word;
// 	int		wflag;

// 	i = 0;
// 	word = 0;
// 	wflag = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 		{
// 			if (!wflag)
// 			{
// 				wflag = 1;
// 				word++;
// 				if (word == w)
// 					return (cut_word(&str[i], c));
// 			}
// 		}
// 		else
// 			wflag = 0;
// 		i++;
// 	}
// 	return (&str[i]);
// }

// char		**ft_split(char const *str, char c)
// {
// 	int		i;
// 	int		k;
// 	char	*newstr;
// 	char	**tab;

// 	i = 0;
// 	if (!str || (tab = (char**)malloc(sizeof(char*) *
// 					(get_words((char *)str, c) + 1)))
// 			== NULL)
// 		return (NULL);
// 	while (i < get_words((char *)str, c))
// 	{
// 		k = 0;
// 		newstr = get_word((char *)str, i + 1, c);
// 		while (newstr[k])
// 			k++;
// 		if ((tab[i] = (char*)malloc(sizeof(char) * k + 1)) == NULL)
// 			return (NULL);
// 		tab[i] = newstr;
// 		tab[i][k] = '\0';
// 		i++;
// 	}
// 	tab[i] = NULL;
// 	return (tab);
// }
