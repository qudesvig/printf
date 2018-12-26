/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:18:46 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/19 16:50:39 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long			ft_int_to_llong(int nb)
{
	return ((long long)nb);
}

long long			ft_long_to_llong(long nb)
{
	return ((long long)nb);
}

unsigned long long	ft_ulong_to_ullong(unsigned long nb)
{
	return ((unsigned long long)nb);
}

unsigned long long	ft_uint_to_ullong(unsigned int nb)
{
	return ((unsigned long long)nb);
}

long double			ft_dbl_to_longdbl(double nb)
{
	return ((long double)nb);
}
