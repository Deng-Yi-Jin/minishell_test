/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:58:28 by sinlee            #+#    #+#             */
/*   Updated: 2024/06/13 19:46:56 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// implementation of ft_strlen function

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && *str++)
		len++;
	return (len);
}
