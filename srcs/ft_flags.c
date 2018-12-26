/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:38:29 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/26 15:03:01 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	ft_get_preci(const char *format, char type)
{
	int i;

	i = 0;
	while (!ft_is_type(format[i]))
	{
		if (format[i] == '.')
		{
			while (format[i] == '.')
				i++;
			return (ft_atoi(&format[i]));
		}
		i++;
	}
	if (type == 'f')
		return (6);
	if (type == 's')
		return (-1);
	return (1);
}

int			ft_is_flag(char c)
{
	if (c == ' ' || c == '#' || c == '0' || c == '+' || c == '-')
		return (1);
	return (0);
}

long long	ft_minlen(const char *format)
{
	int i;

	i = 0;
	while (ft_is_flag(format[i]))
		i++;
	return (ft_atoi(&format[i]));
}

char		*ft_apply_flags(t_flag *flag, char *str)
{
	size_t len;

	len = ft_strlen(str) - ((str[0] == '-') ? 1 : 0);
	if (flag->sign && str[0] == '-')
		flag->sign = 0;
	if (flag->preci == 0 && str[0] == '0' && flag->type != '%' && flag->type != 'c')
	{
		ft_strdel(&str);
		if (flag->sharp && flag->type == 'x')
			flag->sharp = 0;
		ft_strdel(&str);
		str = ft_strdup("");
	}
	else if (((long long)len < flag->preci && flag->type != 'c' && flag->type != 'p' && flag->type != 'f') || flag->type == 's')
		str = ft_apply_preci(flag->preci, str, flag->type);
	else if ((long long)len < flag->preci && flag->type == 'p' && flag->type != 'f')
		str = ft_apply_preci(flag->preci, str, flag->type);
	flag->complet = (flag->min_len > flag->preci) ? flag->min_len - ft_strlen(str) : 0;
	if (flag->zero)
	{
		if (flag->sharp)
			str = ft_apply_zero(str, flag->complet - 2);
		else if (flag->sign || flag->space)
			str = ft_apply_zero(str, flag->complet - 1);
		else
			str = ft_apply_zero(str, flag->complet);
	}
	if (flag->sharp)
		str = ft_apply_sharp(str, flag->type);
	flag->complet = (flag->min_len > flag->preci) ? flag->min_len - ft_strlen(str) : 0;
	if (flag->sign)
		str = ft_apply_sign(str);
	flag->complet = (flag->min_len > flag->preci) ? flag->min_len - ft_strlen(str) : 0;
	if (flag->space && str[0] != '-' && str[0] != '+')
		str = ft_apply_space(str);
	flag->complet = (flag->min_len > flag->preci) ? flag->min_len - ft_strlen(str) : 0;
	if (flag->sp_front)
		str = ft_apply_sp_front(str, flag->complet);
	else if (flag->sp_behind)
		str = ft_apply_sp_behind(str, flag->complet);
	flag->complet = (flag->min_len > flag->preci) ? flag->min_len - ft_strlen(str) : 0;
	if (flag->complet > 0)
		str = ft_apply_sp_front(str, flag->complet);
	else if (flag->min_len > (long long)ft_strlen(str) && flag->type == 's')
		str = ft_apply_sp_front(str, flag->min_len - ft_strlen(str));
	return (str);
}

char		*ft_get_flags(const char *format, char *str, char type)
{
	t_flag	light;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_init_light(&light, format, type);
	ft_set_light(&light, format);
	return (ft_apply_flags(&light, str));
}
