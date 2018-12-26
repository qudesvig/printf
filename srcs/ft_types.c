/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:44:42 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/17 12:05:44 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (1);
	else if (c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else if (c == 'f' || c == '%')
		return (1);
	return (0);
}

char	ft_type(const char *format)
{
	int		i;

	i = 0;
	while (format[i] && !ft_is_type(format[i]))
		i++;
	return (format[i]);
}
