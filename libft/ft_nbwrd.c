/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbwrd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:10:00 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/12 14:18:40 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_nbwrd(char const *s, char c)
{
	int i;
	int ret;

	i = 1;
	ret = 0;
	if (!s)
		return (0);
	if (s[0] != c)
		ret++;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i - 1] == c)
				ret++;
		}
		i++;
	}
	return (ret);
}
