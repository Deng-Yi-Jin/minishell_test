/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:40:07 by geibo             #+#    #+#             */
/*   Updated: 2024/03/11 01:20:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_expansion(t_ast **ast)
{
	t_ast	*current_node;
	t_ast	*current_sibling;
	bool	is_dollar;

	current_node = (*ast)->child;

}