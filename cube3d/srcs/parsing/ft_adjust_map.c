#include "../../includes/cub3D.h"

char	*noblank(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			s[i] = '1';
		i++;
	}
	return (s);
}

char	*adjust_str(char *tmp, char *m, int stock)
{
	int	k;

	k = 0;
	while (stock)
	{
		if (m[k])
			tmp[k] = m[k];
		else
			tmp[k] = '1';
		k++;
		stock--;
	}
	tmp[k] = '\0';
	return (tmp);
}

void 	adjust_map(t_data *d)
{
	int 		i;
	unsigned int	stock;
	char		**tmp;
	int		j;
	char		**m = d->map;

	i = 0;
	j = 0;
	stock = 0;
	while (m[i])
	{
		m[i] = noblank(m[i]);
		stock = (stock > ft_strlen(m[i])) ? stock : ft_strlen(m[i]);
		i++;
	}
	if (!(tmp = malloc(sizeof(char*) * i)))
		return ;
	while (j < i)
	{
		if (!(tmp[j] = malloc(sizeof(char) * stock)))
			return ;
		tmp[j] = adjust_str(tmp[j], m[j], stock);
		j++;
	}
	tmp[i] = NULL;
	i = 0;
	while (m[i])
	{
		free(m[i]);
		m[i] = NULL;
		i++;
	}
	d->map = tmp;
}
