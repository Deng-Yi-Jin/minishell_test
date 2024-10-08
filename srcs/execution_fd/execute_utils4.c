/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:26:10 by geibo             #+#    #+#             */
/*   Updated: 2024/09/17 13:52:11 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_outfile(char *file_name, char **redir_list, int *outfilefd, int *i)
{
	if (is_redir_out(redir_list[*i]) || is_redir_append(redir_list[*i]))
	{
		file_name = redir_list[*i + 1];
		if (is_redir_out(redir_list[*i]))
			*outfilefd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (is_redir_append(redir_list[*i]))
			*outfilefd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
}

int	get_infilefd(char **redir_list)
{
	char	*file_name;
	int		infilefd;
	int		i;

	infilefd = 0;
	i = 0;
	if (redir_list == NULL)
		return (infilefd);
	while (redir_list[i])
	{
		if (is_redir_in(redir_list[i]) || ft_strcmp(redir_list[i], "<<") == 0)
		{
			if (infilefd != 0)
				close(infilefd);
			file_name = redir_list[i + 1];
			infilefd = open(file_name, O_RDONLY, 0644);
			if (infilefd == -1)
			{
				printf("%s: No such file or directory\n", file_name);
				break ;
			}
		}
		i++;
	}
	return (infilefd);
}

int	get_outfilefd(char **redir_list)
{
	char	*file_name;
	int		out_fd;
	int		i;

	out_fd = 0;
	i = -1;
	if (redir_list == NULL)
		return (out_fd);
	while (redir_list[++i])
	{
		open_outfile(file_name, redir_list, &out_fd, &i);
		if (out_fd == -1)
		{
			printf("%s: No such file or directory\n", file_name);
			break ;
		}
	}
	return (out_fd);
}

void	dup2_error(void)
{
	perror("dup2");
	exit(EXIT_FAILURE);
}

void	close_fd(int *previous_fd, int *infile_fd)
{
	close(previous_fd[1]);
	if (dup2(previous_fd[0], STDIN_FILENO) == -1)
		dup2_error();
	close(previous_fd[0]);
}
