/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:58:27 by djin              #+#    #+#             */
/*   Updated: 2024/04/01 17:57:09 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIPE 1
#define OR 2
#define REDIR_IN 3
#define HERE_DOC 4
#define REDIR_OUT 5
#define REDIR_OUT_APPEND 6
#define DOLLAR 7
#define BOO_NO_EXPANSION 8
#define DOMESTIC_EXPANSION 9
#define WORD 10
#define DIGIT 11
#define CMD 12
#define SPACE 13
#define QUOTE 14
#define CMD_EXPANSION 15
#define FLAGS 16

// enum Flags {
// 	PIPE,
// 	OR,
// 	..
// }

// Structure to hold tokens
typedef struct s_token
{
	int				type;
	char			*cmd;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;
