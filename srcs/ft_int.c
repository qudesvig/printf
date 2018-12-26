/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:10:31 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/26 15:04:57 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_int_to_str(long long nb)
{
	if (nb == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	return (ft_convert_base(nb, "0123456789"));
}

long long	ft_char_to_llong(int nb)
{
	long long	tmp;
	int			i;

	tmp = 0;
	i = 0;
	if (nb < 0)
	{
		while (i > nb)
		{
			tmp--;
			if (tmp == -129)
				tmp = 127;
			i--;
		}
	}
	else
	{
		while (i < nb)
		{
			tmp++;
			if (tmp == 128)
				tmp = -128;
			i++;
		}
	}
	return (tmp);
}

long long	ft_short_to_llong(int nb)
{
	long long	tmp;
	int			i;

	tmp = 0;
	i = 0;
	if (nb < 0)
	{
		while (i > nb)
		{
			tmp--;
			if (tmp == -32769)
				tmp = 32767;
			i--;
		}
	}
	else
	{
		while (i < nb)
		{
			tmp++;
			if (tmp == 32768)
				tmp = -32768;
			i++;
		}
	}
	return (tmp);
}

char		*ft_int_to_char(int nb)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	if (nb == 0)
		str[0] = -1;
	else
		str[0] = nb;
	str[1] = '\0';
	return (str);
}
