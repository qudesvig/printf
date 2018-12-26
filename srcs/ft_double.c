/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:28:01 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/26 15:01:49 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	ft_ten_pow(int nb)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (i < nb)
	{
		ret *= 10;
		i++;
	}
	return (ret);
}

char		*ft_get_dec(int nb, int remain)
{
	char		*str;
	char		*tmp;
	char		*tmp2;
	int			i;

	i = 1;
	if (nb == 0)
	{
		if (remain >= 8)
			str = ft_strdup("00000000");
		else
		{
			tmp = ft_strdup("0");
			str = ft_strdup("0");
			while (i <= remain)
			{
				tmp2 = ft_strdup(str);
				ft_strdel(&str);
				str = ft_strjoin(tmp2, tmp);
				ft_strdel(&tmp2);
				i++;
			}
			ft_strdel(&tmp);
		}
		return (str);
	}
	str = ft_itoa(nb);
	return (str);
}

char		*ft_longdbl_to_str(long double nb, int preci)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	int		cycle;

	cycle = 0;
	str = ft_convert_base((long)nb, "0123456789");
	str = ft_realloc(str, sizeof(str) + 1);
	str = ft_strcat(str, ".");
	if (preci < cycle)
	{
		nb -= (int)nb;
		tmp = ft_get_dec((int)(nb * ft_ten_pow(preci) + 0.5), preci);
		str = ft_realloc(str, sizeof(str + sizeof(tmp)));
		str = ft_strcat(str, tmp);
		ft_strdel(&tmp);
	}
	else if (preci >= cycle)
	{
		while (cycle < preci)
		{
			nb -= (int)nb;
			nb *= ft_ten_pow((cycle + 8 > preci) ? preci - cycle : 8);
			tmp = ft_get_dec((int)nb, preci - cycle);
			tmp2 = ft_strdup(str);
			ft_strdel(&str);
			str = ft_strjoin(tmp2, tmp);
			cycle += (cycle + 8 > preci) ? preci - cycle : 8;
			ft_strdel(&tmp);
			ft_strdel(&tmp2);
		}
	}
	return (str);
}
