/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:05:29 by kytan             #+#    #+#             */
/*   Updated: 2024/09/16 14:41:06 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strfjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	join_size;
	char	*join;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join_size = s1_len + s2_len + 1;
	join = malloc(join_size);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy(join + s1_len, s2, join_size - s1_len);
	free(s1);
	return (join);
}
