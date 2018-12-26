/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:30:40 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/26 15:32:06 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_end(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == -1)
			write(1, "\0", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int		ft_check_type(const char *format, int len)
{
	int i;

	i = 1;
	while (i < len)
	{
		if (ft_is_type(format[i]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_first_no(const char *format)
{
	int i;

	i = 1;
	while (format[i] && !ft_is_type(format[i]))
	{
		if (format[i] != '.' && format[i] != ' ' && format[i] != '+' &&
			format[i] != '-' && format[i] != '#' && format[i] != 'h' &&
			format[i] != 'l' && format[i] != 'L' && !ft_isdigit(format[i]))
			return (i);
		i++;
	}
	if (!format[i])
		return (i);
	return (0);
}

int		ft_is_no(const char *format)
{
	int i;

	i = 1;
	while (format[i] && !ft_is_type(format[i]))
	{
		if (format[i] != '.' && format[i] != ' ' && format[i] != '+'
				&& format[i] != '-' && format[i] != '#' && format[i] != 'h'
				&& format[i] != 'l' && format[i] != 'L' &&
				!ft_isdigit(format[i]))
			return (1);
		i++;
	}
	if (!format[i])
		return (1);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	char	*buff;
	va_list	params;
	int		i[2];
	int		len;
	int		ret;

	i[0] = 0;
	i[1] = 0;
	ret = 0;
	va_start(params, format);
	len = ft_strlen(format);
	if (!(buff = ft_strnew(len + 1)))
		return (-1);
	while (format[i[0]] && i[0] < len)
	{
		if (format[i[0]] == '%' && ft_is_no(&format[i[0]]) && i[0] < len)
			i[0] += ft_first_no(&format[i[0]]);
		if (format[i[0]] == '%' && i[0] < len && format[i[0] + 1])
		{
			ret += i[1];
			ft_putstr(buff);
			ft_get_param(&format[i[0] + 1], params, &ret);
			ft_bzero(buff, i[1]);
			i[0] += ft_param_len(&format[i[0] + 1]) + 1;
			i[1] = 0;
		}
		else if (i[0] < len && format[i[0]] != '%')
		{
			buff[i[1]] = format[i[0]];
			i[1]++;
			i[0]++;
		}
	}
	ft_putstr(buff);
	ft_strdel(&buff);
	va_end(params);
	return (ret + i[1]);
}
