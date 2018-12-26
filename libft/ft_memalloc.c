/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:17:13 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/12 14:18:03 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		ret[i] = 0;
		i++;
	}
	return ((void*)ret);
}
