/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 00:24:01 by geibo             #+#    #+#             */
/*   Updated: 2024/09/16 14:39:11 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include "minishell.h"
# include "execute.h"

bool	is_redir(char *cmd);
bool	is_redir_in(char *cmd);
bool	is_redir_out(char *cmd);
bool	is_redir_append(char *cmd);
void	redirect(t_exec *exec, int *infilefd, int *outfilefd);
int		return_after_redir(t_exec *exec, int i);
void	process_command(t_exec *exec, int *i);
void	process_redirection(t_exec *exec, int *i);

#endif