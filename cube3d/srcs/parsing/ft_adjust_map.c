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
	if (!(tmp = malloc(sizeof(char) * stock + 1)))
		return NULL;
	while (m[k])
	{
		tmp[k] = m[k];
		k++;
		stock--;
	}
	while (stock)
	{
		tmp[k] = '*';
		k++;
		stock--;
	}
	tmp[k] = '\0';
	return (tmp);
}

void 	adjust_map(t_data *d)
{
	int 			i;
	unsigned int	stock;
	char			**tmp;
	int				j;

	i = 0;
	j = 0;
	stock = 0;
	while (d->map[i])
	{
		stock = (stock > ft_strlen(d->map[i])) ? stock : ft_strlen(d->map[i]);
		i++;
	}
	printf("stock : [%d] \n i : [%d]\n", stock , i);
	if (!(tmp = calloc(i + 1, sizeof(char*))))
		return ;
	while (j < i)
	{
		tmp[j] = adjust_str(tmp[j], d->map[j], stock);
		j++;
	}
	tmp[i] = NULL;
	i = 0;
	while (d->map[i])
	{
		free(d->map[i]);
		d->map[i] = NULL;
		i++;
	}
	d->map = tmp;
}
