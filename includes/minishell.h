/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:06:06 by sinlee            #+#    #+#             */
/*   Updated: 2024/10/04 11:02:41 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include "color.h"
# include "execute.h"
# include "libft.h"
# include "parse.h"
# include "redir.h"
# include "tokens.h"

# define PATH_MAX 4096
# define LOGIN_NAME_MAX 256
# define MAX_ENV_VARS 10240

typedef struct env_var_s
{
	char		*key;
	char		*value;
}				t_env_var;

typedef struct s_main
{
	int				nuclear_status;
	t_env_var		**env_vars;
}				t_main;

typedef struct s_traverse
{
	bool		is_pipe;
	int			n_cmd;
	int			word;
}				t_traverse;

extern t_main	*g_main;

char			*new_line(char *input, char c);
bool			is_bracket(char c);
char			*error_bracket(char **split, int word);

char			*dquote(char *input);

void			perror_color(char *str);
void			error_exit(char *str, bool is_perror);
void			execute_exit(int exit_status);

char			*prompt_msg(char prompt[LOGIN_NAME_MAX + PATH_MAX + 20]);

void			init(char **envp);
void			init_signals(void);
char			**ft_split(const char *str, const char *delim);

int				execute_builtin(char *inpt, char *args[N_ARGS], char **envp);
void			ft_free_path_env(char **path_env);
char			*get_path(char *cmd, char **envp);
char			*find_command_path(char *command, char **envp);
int				is_command(char *cmd, char **envp);
void			parse_input(char *input, char **envp);

void			init_new_env_var(t_env_var **new_env_vars, int num_env_vars,
					char *key, char *value);
void			init_null_env_var(t_env_var **new_env_vars, int num_env_vars,
					char *key, char *value);
size_t			new_vars_ct(char *unset_key);

void			add_env_vars(char *key, char *value);
void			modify_env_vars(char *key, char *value);
void			delete_env_vars(char *key);
t_env_var		*find_env_vars(char *key);
int				find_env(char *key, char **envp);
char			*ft_getenv(char *key);
void			free_env_vars(void);
bool			flip_bool_env_vars(char *key);

int				execute_echo(char **args);

t_env_var		**dup_darr(char **arr);
void			free_darr(t_env_var **arr);
void			free_jutsu(bool darr, char *key, char *value);

int				execute_cd(char *args[N_ARGS], char **envp);
int				execute_export(char **args);
int				welcome_msg(void);

int				ft_snprintf(char *str, size_t size, const char *format, ...);
char			*ft_strtok(char *str, const char *delim);
void			*ft_malloc(size_t size);

/* NEW UTILS ADDED FOR EXPANSION */

char			*ft_strfjoin(char *s1, char *s2);

// Token linked listfunctions
t_token			*lst_first_last(t_token *tokens, bool is_last);
t_token			*add_tokens(t_token *tokens, char *cmd, int type);
t_token			*create_token(char *cmd, int type);
void			free_stack(t_token **tokens, void (*del)(void *), bool loop,
					char *input);
// void		del(void *content);
void			print_stack(t_token *tokens);
void			free_split(char **str);
t_token			*lst_go_back(t_token *tokens);
t_token			*add_null_token(t_token *tokens);

// GetNextLine
char			*get_next_line(int fd);

// expand dollar
char			*expand_dollar(char *input);

// Lexer utils
void			lexing(char *input, t_token **tokens, int *i, int *count_words);
bool			ft_bracket(char input);
void			start_lex(char *input, t_token **tokens);
bool			ft_symbol(char input);
int				ft_return_op(char input);
void			ft_redir(char *input, int *i, t_token **tokens);
void			ft_pipe(char *input, int *i, t_token **tokens);
void			quoting(char *str, int *i, int *count_words, char c);
void			quotation(char *input, int *i, int *count_words, char c);
void			dollar(char *input, int *i, int *count_words);
char			*trim_quotation(char *str);

void			print_token(t_token *tokens, bool to_first, char *str);

void			test_traverse(void);
void			print_my_env_vars(void);
void			del(void *content);
bool			error_return(t_token **tokens, char *input);
bool			check_consecutive_tokens(t_token *token, t_token **tokens,
					char *input);
bool			check_first_token(t_token *token, t_token **tokens,
					char *input);
void			print_error_and_free(const char *error_message,
					t_token **tokens, char *input);
size_t			total_g_env_vars(void);
void			update_g_envp(void);
void			print_g_envp(void);
void			print_tokens(t_token **tokens);
bool			check_last_token(t_token *token, t_token **tokens, char *input);

#endif