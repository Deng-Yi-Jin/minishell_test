/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:54:15 by codespace         #+#    #+#             */
/*   Updated: 2024/10/04 11:03:17 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "parse.h"
# define N_ARGS 2560
# include <stdbool.h>
# include <stddef.h>

typedef struct s_exec
{
	char			**cmd;
	struct s_exec	*next;
	struct s_exec	*prev;
	char			**cmd_list;
	char			**redir_list;
	pid_t			pid;
	int				*type;
	int				fd[2];
	int				infile;
	int				outfile;
}					t_exec;

t_exec				*create_exec_node(char **cmd, int *type);
bool				add_cmd_to_db_lst(t_ast **ast, t_exec *exec, int depth);
t_exec				*join_exec_nodes(t_exec *exec, char **cmd, int *type);
t_exec				*executing(t_ast **ast, t_exec *exec);
void				exec_pipe(t_exec *exec, char **envp, char *command_path);
bool				execution(t_exec *exec, char **envp, char *command_path);
void				free_exec(t_exec *exec);
void				print_exec(t_exec *exec);

int					total_command(t_exec *exec, int count);
void				check_match_cmd(t_exec *exec, char **envp, int *i);

void				execute(t_exec *exec, char **envp);
bool				last_cmd(t_exec *exec);
void				manage_pipe_child(t_exec *exec, int infile_fd,
						int outfile_fd);
void				manage_pipe_parent(t_exec *exec);
void				manage_lastcmdredir(t_exec *exec, int infile_fd,
						int outfile_fd);
void				restore_fd(int origstdin, int origstdout);
void				init_origio(int origio[]);
void				handle_lastcmd_child(t_exec *exec, int infilefd);
void				handle_lastcmd_parent(t_exec *exec);
void				run_cmd(char **envp, t_exec *exec, char *command_path,
						int *i);
pid_t				create_fork(void);
t_exec				*renamed_here_doc(t_exec *exec, char **envp);
int					ft_sstrlen(char **str);

void				set_exec_type(t_exec *exec, char **envp);
bool				check_command(char *inpt, char *args[N_ARGS], char **envp);
void				handle_not_heredoc(char *tmp1, t_exec *temp, int *i);
void				copy_n_paste(char **another, char **temp, int *i);

t_exec				*redirection(t_exec *exec);

char				*expansion(char **split);
int					no_expansion_needed(char *s);
char				*full_expansion(char **split, char *sep);
char				*env_expansion(char **split_q);

char				*expanded(char *split_q);

int					exp_flag(char *s, char *split_q);
char				**ft_splitq(char const *s, char c);
static size_t		count_words(char const *s, char c);

char				*cp_to_expanded(char *split_q, char *output, size_t size);
char				*exp_dollar_env(char *env_v, char *output, int *j,
						size_t size);

size_t				calc_envsize(char *split_q);
size_t				calc_envlen(char *s, int *i);
char				*extract_key(char *env_s);
char				*extract_value(char *env_key);

char				ft_quote(char *s);
char				*ft_strldup(char *src, ptrdiff_t size);
int					execute_pwd(void);

int					execute_env(char **args);
int					execute_unset(char **args);

int					get_outfilefd(char **redir_list);
int					get_infilefd(char **redir_list);
bool				get_redirfd(t_exec *exec, int *infilefd, int *outfilefd,
						char **envp);

void				child_outfd_setup(int outfile_fd);
void				child_infd_setup(int infile_fd);
pid_t				create_fork(void);
void				dup2_error(void);
void				close_fd(int *previous_fd, int *infile_fd);
bool				handle_file_descriptor(int *fd, int (*get_fd_func)(char **),
						t_exec *exec);
int					count_cmd_line(t_exec *exec, int i);
void				allocate_cmd_list(t_exec *exec, int cmd_line);
void				copy_cmd_to_list(t_exec *exec);
void				start_command_exec(char *command_path, char **envp,
						t_exec *exec, int saved_stdin);

#endif