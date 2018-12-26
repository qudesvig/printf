/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:58:16 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/26 15:00:03 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_apply_preci(long long preci, char *str, char type)
{
	long long	i;
	long long	len;
	char		*tmp;

	i = 0;
	tmp = ft_strdup(str);
	len = (long long)ft_strlen(tmp) - ((tmp[0] == '-') ? 1 : 0);
	if (preci == 0)
	{
		ft_strdel(&str);
		return (ft_strdup(""));
	}
	if (type == 's')
	{
		if (len > preci && preci != -1)
			ft_bzero(&str[preci], len - preci);
	}
	else if (len < preci)
	{
		ft_strdel(&str);
		if (!(str = ft_strnew(len + (preci - len) + 1)))
			return (NULL);
		while (i < preci - len)
		{
			str[i] = '0';
			i++;
		}
		if (tmp[0] == '-')
		{
			str = ft_strjoin("-", str);
			str = ft_strcat(str, &tmp[1]);
		}
		else
			str = ft_strcat(str, tmp);
	}
	ft_strdel(&tmp);
	return (str);
}

char	*ft_apply_sp_front(char *str, long long complet)
{
	long long	i;
	char		*tmp;
	char		*tmp2;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + complet + 1))))
		return (NULL);
	tmp2 = ft_strdup(str);
	ft_strdel(&str);
	while (i < complet)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = 0;
	tmp = ft_strcat(tmp, tmp2);
	str = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (str);
}

char	*ft_apply_sp_behind(char *str, long long complet)
{
	long long	i;
	long long	len;
	char		*tmp;

	i = ft_strlen(str);
	len = i + ((complet >= 0) ? complet : 0);
	if (!(tmp = ft_strdup(str)))
		return (NULL);
	if (!(tmp = ft_realloc(tmp, len)))
		return (NULL);
	while (i < len)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = 0;
	ft_strdel(&str);
	return (tmp);
}

char	*ft_apply_zero(char *str, long long complet)
{
	long long	i;
	char		*tmp;
	char		*tmp2;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + complet + 1))))
		return (NULL);
	if (str[0] == '-')
	{
		tmp[0] = '-';
		i++;
		complet++;
		tmp2 = ft_strdup(&str[1]);
	}
	else
		tmp2 = ft_strdup(str);
	ft_strdel(&str);
	while (i < complet)
	{
		tmp[i] = '0';
		i++;
	}
	tmp[i] = 0;
	tmp = ft_strcat(tmp, tmp2);
	str = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (str);
}
