/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:53:14 by othabchi          #+#    #+#             */
/*   Updated: 2021/07/12 16:30:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include "../project/libft/libft.h"
# include <dirent.h>

typedef struct s_env {
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_data {
	char			**linespt;
	char			**door;
	char			***pipe;
	char			*builtin_str[8];
	char			*line;
	char			*path;
	char			*value;
	char			*name;
	char			*redir;
	int				(*builtin_func[7])(struct s_data *, char **);
	int				nb_element;
	int				fd_stdout;
	int				fd_stdin;
	int				fdd;
	int				is_builtin;
	int				status;
	int				open_the_door;
	int				ret;
	int				sys_func;
	pid_t			pid;
	pid_t			pid_open_the_door;
	struct dirent	*entry;	
	DIR				*folder;
	t_env			*new_;
	t_env			*head;
}					t_data;

t_data				*g_data;
/*
** * * * * * *  MAIN FUNCTION  * * * * * * * * * * * * * * * * * * * * * * * * *
*/
void				minishell(t_data *d, char **envp);
void				sig_handler(int signal);
int					builtin(t_data *d, char **linespt);
int					is_sys_func(t_data *d, char **s, char **envp);
/*
** * * * * * *  BUILTINS * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
char				*adjust_str_export(char *s);
int					pars_export2(char *s);
int					pars_export3(char *s);
void				print_export(t_data *d);
int					ft_pwd(t_data *d, char **linespt);
int					ft_echo(t_data *d, char **linespt);
int					ft_exit(t_data *d, char **linespt);
int					ft_export(t_data *d, char **linespt);
int					ft_cd(t_data *d, char **linespt);
int					ft_env(t_data *d, char **linespt);
int					ft_unset(t_data *d, char **linespt);
int					pars_unset(char **s, t_data *d);
void				remove_variable(char *s, t_data *d);
/*
** * * * * * *  UTILS  * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
/*
**					~ sys func ~
*/
int					file_exist(char **s, t_data *d);
/*
**					~ redirection ~
*/
int					redirection(t_data *d, char **s);
int					arg_cancel_redir(char **s);
int					error_redir(char *s);
int					open_the_door(t_data *d);
char				**expression_without_redir(char **s);
/*
**					~ split ~
*/
char				**ft_split_minishell(t_data *d, char *s);
char				**split_expression(char **s, t_data *d);
char				**real_split2(char **s, char **tab);
char				*adjust_str(char *s);
int					basic_word(char *s, char **tab, int *j);
int					quote_word(char *s, char **tab, int *j);
int					doll_word(char *s, char **tab, int	*j);
int					count_words(char *s);
void				count_quote_word(char *s, int *i, int *word);
void				count_doll_word(char *s, int *i, int *word);
void				count_basic_word(char *s, int *i, int *word);
/*
**					~ pipe ~
*/
void				exec_pipe(t_data *d, char **expression, char **envp);
int					there_is_pipe(char **s);
char				***split_each_cmd_btwn_pipe(char **s);
/*
**					~ list ~
*/
char				*change_doll_in_double_quote(char *s, t_data *d);
char				*find_var(char *s, t_data *d);
char				*change_env_var(t_data *d, char *s);
int					env_var_already_exist(t_data *d);
void				free_list(t_data *d);
void				fill_list(t_data *d);
void				update_return_cmd(char *s1, char *s2, t_data *d);
/*
**					~ parsing ~
*/
void				nb_spaces(t_data *d, char **s);
char				*transform_slash(char *s);
int					check_line(t_data *d);
int					check_quote_sep_redir(char *s);
/*
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
#endif
