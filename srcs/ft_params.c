/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:48:05 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/26 15:08:07 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_param_len(const char *str)
{
	int i;

	i = 0;
	while (str[i] && !ft_is_type(str[i]))
		i++;
	return (i + 1);
}

int		ft_is_conv(const char *format)
{
	int i;

	i = 0;
	while (!ft_is_type(format[i]))
		i++;
	i--;
	while (i >= 0)
	{
		if (format[i] == 'l' || format[i] == 'h' || format[i] == 'j')
			return (1);
		i--;
	}
	return (0);
}

int		ft_get_conv(const char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (!ft_is_type(str[i]))
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
		{
			i++;
			ret = (ret < 1) ? 1 : ret;
		}
		else if (str[i] == 'h' && str[i + 1] != 'h')
			ret = (ret < 2) ? 2 : ret;
		else if ((str[i] == 'l' && str[i + 1] != 'l'))
			ret = (ret < 3) ? 3 : ret;
		else if ((str[i] == 'l' && str[i + 1] == 'l') || str[i] == 'j' || str[i] == 'z')
		{
			i++;
			ret = 4;
		}
		else if (str[i] == 'L')
			return (5);
		i++;
	}
	return (ret);
}

void	ft_get_param(const char *format, va_list param, int *len)
{
	char				*str;
	char				type;
	int					conv;
	unsigned long long	var;
	int					preci;

	type = ft_type(format);
	conv = (ft_is_conv(format)) ? ft_get_conv(format) : 0;
	str = ft_strdup("%");
	if (type == '%')
		*len = *len;
	else if (type == 'd' || type == 'i')
	{
		ft_strdel(&str);
		if (conv == 3)
			str = ft_int_to_str(ft_long_to_llong(va_arg(param, long)));
		else if (conv == 4)
			str = ft_int_to_str(va_arg(param, long long));
		else if (conv == 1)
			str = ft_int_to_str(ft_char_to_llong(va_arg(param, int)));
		else if (conv == 2)
			str = ft_int_to_str(ft_short_to_llong(va_arg(param, int)));
		else if (conv == 0)
			str = ft_int_to_str(ft_int_to_llong(va_arg(param, int)));
	}
	else if (type == 'o' || type == 'u' || type == 'x' || type == 'X')
	{
		ft_strdel(&str);
		if (conv == 3)
			str = ft_uint_to_str(ft_ulong_to_ullong(va_arg(param, unsigned long)), type);
		else if (conv == 4)
			str = ft_uint_to_str(va_arg(param, unsigned long long), type);
		else if (conv == 2)
			str = ft_uint_to_str(ft_uint_to_ullong((unsigned short)va_arg(param, unsigned int)), type);
		else if (conv == 1)
			str = ft_uint_to_str(ft_uint_to_ullong((unsigned char)va_arg(param, unsigned int)), type);
		else if (conv == 0)
			str = ft_uint_to_str(ft_uint_to_ullong(va_arg(param, unsigned int)), type);
	}
	else if (type == 's')
	{
		ft_strdel(&str);
		str = va_arg(param, char*);
		if (str == NULL)
		{
			ft_strdel(&str);
			str = ft_strdup("(null)");
		}
		else
			str = ft_strdup(str);
	}
	else if (type == 'p')
	{
		ft_strdel(&str);
		var = ft_get_addr(va_arg(param, void*));
		str = ft_uint_to_str(var, 'x');
	}
	else if (type == 'f')
	{
		ft_strdel(&str);
		preci = ft_get_preci(format, type);
		if (conv < 5)
			str = ft_longdbl_to_str(ft_dbl_to_longdbl(va_arg(param, double)), preci);
		else
			str = ft_longdbl_to_str(va_arg(param, long double), preci);
	}
	else
	{
		ft_strdel(&str);
		str = ft_int_to_char(va_arg(param, int));
	}
	str = ft_get_flags(format, str, type);
	*len += ft_strlen(str);
	ft_putstr_end(str);
	ft_strdel(&str);
}
