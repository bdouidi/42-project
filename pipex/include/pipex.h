/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:26:32 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/09 16:35:32 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include "../project/libft/libft.h"
# include <dirent.h>
# include "../project/libft/libft.h"

typedef struct s_env {
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_data {
	char			***pipe;
	int				fd_stdin;
	int				fd_stdout;
	int				status;
	int				pid;
	int				fdd;
	int				test;
	t_env			*new_;
	t_env			*head;
}					t_data;

int					pipex(char **av, t_data *d);
void				exec_pipex(char **s, t_data *d);
int					redirection(char *s1, char *s2, t_data *d);
char				***split_each_cmd_btwn_pipe(char *s1, char *s2);
int					file_exist(char **s, t_data *d);

#endif
