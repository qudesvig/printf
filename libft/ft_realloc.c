/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:42:43 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/14 15:12:24 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

char	*ft_realloc(char *line, unsigned int size)
{
	char	*tmp;

	if (!(tmp = ft_strnew(size)))
		return (NULL);
	ft_strncpy(tmp, line, size);
	free(line);
	return (tmp);
}
