/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:21:56 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/26 15:01:20 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_apply_sharp(char *str, char type)
{
	char	*tmp;
	char	*tmp2;

	if ((ft_strlen(str) == 1 && str[0] == '0' && type != 'p')
			|| (type == 'o' && str[0] == '0'))
		return (str);
	if (!(tmp = ft_strnew(ft_strlen(str) + ((type == 'o') ? 2 : 3))))
		return (NULL);
	tmp2 = ft_strdup(str);
	tmp[0] = '0';
	if (type == 'o')
	{
		tmp[1] = '\0';
		tmp = ft_strcat(tmp, str);
	}
	else
	{
		tmp[1] = (type == 'p') ? 'x' : type;
		tmp[2] = '\0';
		ft_strcat(tmp, tmp2);
	}
	ft_strdel(&str);
	ft_strdel(&tmp2);
	return (tmp);
}

char		*ft_apply_sign(char *str)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	tmp[0] = '+';
	tmp[1] = 0;
	tmp = ft_strcat(tmp, str);
	ft_strdel(&str);
	return (tmp);
}

char		*ft_apply_space(char *str)
{
	char	*tmp;
	char	*tmp2;

	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	tmp2 = ft_strdup(str);
	tmp[0] = ' ';
	tmp[1] = 0;
	tmp = ft_strcat(tmp, tmp2);
	ft_strdel(&tmp2);
	ft_strdel(&str);
	return (tmp);
}
