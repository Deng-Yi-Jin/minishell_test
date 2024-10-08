/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:18:19 by codespace         #+#    #+#             */
/*   Updated: 2024/10/03 21:14:15 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	perror_color(char *str)
{
	char	msg[1024];

	ft_snprintf(msg, sizeof(msg), "%s%s%s", RED, str, CYAN);
	perror(msg);
	printf("%s", RESET_COLOR);
}

void	error_exit(char *str, bool is_perror)
{
	char	*msg;

	msg = malloc(1024);
	ft_snprintf(msg, 1024, "%s%s%s", RED, str, RESET_COLOR);
	if (is_perror)
		perror(msg);
	else
		printf("%s", msg);
	free(msg);
	exit(errno);
}

void	free_split_debug(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%d %p %s\n", i, str[i], str[i]);
		free(str[i]);
		i++;
	}
	printf("str %p\n", str);
	free(str);
}

void	execute_exit(int exit_status)
{
	printf("%sBELLA CIAO%s\n", BLUE_BOLD, RESET_COLOR);
	free_env_vars();
	g_main->nuclear_status = exit_status;
	exit(exit_status);
}

// void	free_jutsu(bool darr, char *key, char *value)
// {
// 	if (darr == true)
// 		free_darr(envp);
// 	if (key != NULL)
// 		free(key);
// 	if (value != NULL)
// 		free(value);
// }
