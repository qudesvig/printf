/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:39:28 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/26 14:32:14 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		main(int ac, char **av)
{
	void	*str;
	int			i = 2147483647;
	char c;
	unsigned long long	d = 110;
	short 		t = 2;
	double	f = 155.888885500000000001;

	c = 'a';

	str = strdup("Bonjour comment vas tu ?\n");
	//d = (long long)(str);
	if (ac)
		(void)av;
	printf("\n%d\n", printf("%05.Z", 123));
	return (0);
}
