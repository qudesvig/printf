/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:45:16 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/26 15:07:25 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_init_light(t_flag *flag, const char *format, char type)
{
	flag->sp_front = 0;
	flag->sp_behind = 0;
	flag->zero = 0;
	flag->sharp = 0;
	flag->sign = 0;
	flag->space = 0;
	flag->type = type;
	flag->preci = (type == '%' || type == 'c') ? 0 : ft_get_preci(format, type);
	flag->min_len = ft_minlen(format);
	flag->complet = (flag->preci < flag->min_len) ?
		flag->min_len - flag->preci : 0;
}

int			ft_is_applied(char type, char flag)
{
	if (flag == '+')
	{
		if (type == 'd' || type == 'i' || type == 'f')
			return (1);
	}
	else if (flag == '0')
		return (1);
	else if (flag == '#')
	{
		if (type == 'o' || type == 'x' || type == 'X' || type == 'f')
			return (1);
	}
	else if (flag == ' ')
	{
		if (type == 'd' || type == 'i' || type == 'f')
			return (1);
	}
	return (0);
}

int			ft_is_preci(const char *format)
{
	int i;

	i = 0;
	while (!ft_is_type(format[i]))
	{
		if (format[i] == '.' && ft_isdigit(format[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

void		ft_set_light(t_flag *flag, const char *format)
{
	int		i;

	i = 0;
	while (!ft_is_type(format[i]))
	{
		if (format[i] == '+' && ft_is_applied(flag->type, '+'))
		{
			if (!flag->zero && !flag->sp_behind)
				flag->sp_front = 1;
			flag->sign = 1;
		}
		else if (format[i] == '-')
		{
			flag->sp_behind = 1;
			if (flag->sp_front)
				flag->sp_front = 0;
			if (flag->zero)
				flag->zero = 0;
		}
		else if (format[i] == '0' && !ft_isdigit(format[i - 1]) &&
				format[i - 1] != '.' && ft_is_applied(flag->type, '0') &&
				!flag->sp_behind)
		{
			if (ft_is_preci(format))
				flag->sp_front = 1;
			else
			{
				if (!flag->sp_behind)
					flag->zero = 1;
				flag->sp_front = 0;
			}
		}
		else if (format[i] == '#' && ft_is_applied(flag->type, '#'))
		{
			if (flag->type == 'f' && flag->zero != 1 && flag->sp_behind != 1)
				flag->sp_front = 1;
			else if (flag->type != 'f')
				flag->sharp = 1;
		}
		else if (format[i] == ' ' && ft_is_applied(flag->type, ' '))
		{
			if (flag->sign == 0)
				flag->space = 1;
		}
		i++;
	}
	if (flag->type == 'p')
		flag->sharp = 1;
}
