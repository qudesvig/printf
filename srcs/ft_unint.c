/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:13:06 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/19 12:14:18 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_ulenb(unsigned long long nb, int lenb)
{
	int ret;

	ret = 0;
	while (nb >= (unsigned long long)lenb)
	{
		ret++;
		nb /= (unsigned long long)lenb;
	}
	return (ret + 1);
}

char	*ft_convert_base_u(unsigned long long nb, char *base)
{
	int				i;
	unsigned int	lenb;
	char			*ret;

	i = 0;
	lenb = ft_strlen(base);
	if (!(ret = (char*)malloc(sizeof(char) * ft_ulenb(nb, lenb))))
		return (NULL);
	while (nb >= (unsigned long long)lenb)
	{
		ret[i] = base[nb % (unsigned long long)lenb];
		i++;
		nb /= (unsigned long long)lenb;
	}
	ret[i] = base[nb];
	ret[i + 1] = 0;
	return (ft_strrev(ret));
}

char	*ft_uint_to_str(unsigned long long nb, char type)
{
	if (type == 'o')
		return (ft_convert_base_u(nb, "01234567"));
	else if (type == 'u')
		return (ft_convert_base_u(nb, "0123456789"));
	else if (type == 'x')
		return (ft_convert_base_u(nb, "0123456789abcdef"));
	else if (type == 'X')
		return (ft_convert_base_u(nb, "0123456789ABCDEF"));
	return (NULL);
}
