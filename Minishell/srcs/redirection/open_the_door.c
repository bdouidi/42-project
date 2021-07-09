#include "../../include/minishell.h"

int	nb_key(t_data *d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (d->linespt[i])
	{
		if (ft_strcmp("<<", d->linespt[i]) == 0)
			count += 1;
		i += 1;
	}
	return (count);
}

void	set_key(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->linespt[i])
	{
		if (ft_strcmp("<<", d->linespt[i]) == 0)
		{
			d->linespt[i + 1] = adjust_str(d->linespt[i + 1]);
			d->door[j++] = ft_strdup(d->linespt[i + 1]);
		}
		i += 1;
	}
	d->door[j] = NULL;
}

int	match_key(char **door, int count)
{
	int		i;
	char	*line;

	i = -1;
	line = NULL;
	while (++i < count)
	{
		while (1)
		{
			write(1, "> ", 2);
			get_next_line(0, &line);
			if (g_data->open_the_door == 2)
			{
				line = ft_leak(line);
				return (-1);
			}
			if (!line || (ft_strcmp(line, door[i]) == 0))
			{
				line = ft_leak(line);
				break ;
			}
			line = ft_leak(line);
		}
	}
	return (0);
}

int	exec_match_key(char ***door, int count)
{
	int	pid;
	int	status;
	int	ret;

	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		g_data->pid_open_the_door = pid;
		ret = match_key(*door, count);
		*door = ft_leak_2(*door);
		g_data->open_the_door = 0;
		exit (ret);
	}
	else
		waitpid(pid, &status, 0);
	return (0);
}

int	open_the_door(t_data *d)
{
	int	count;
	int	ret;

	count = nb_key(d);
	d->open_the_door = 0;
	if (count == 0)
		return (0);
	ret = 0;
	d->open_the_door = 1;
	d->door = malloc(sizeof(char *) * (count + 1));
	set_key(d);
	exec_match_key(&d->door, count);
	d->door = ft_leak_2(d->door);
	if (d->open_the_door == 2)
		ret = -1;
	return (ret);
}
