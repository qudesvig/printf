/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:20:46 by qudesvig          #+#    #+#             */
/*   Updated: 2018/12/19 17:42:41 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct		s_flag
{
	int				sp_front;
	int				sp_behind;
	int				zero;
	int				sharp;
	int				sign;
	int				space;
	long long		preci;
	long long		min_len;
	long long		complet;
	char			type;
}					t_flag;

void				ft_putstr_end(char *str);
int					ft_printf(const char *format, ...);

int					ft_is_type(char c);
void				ft_get_param(const char *format, va_list param, int *len);
int					ft_param_len(const char *str);

char				ft_type(const char *format);

long long			ft_short_to_llong(int nb);
long long			ft_char_to_llong(int nb);
long long			ft_int_to_llong(int nb);
long long			ft_long_to_llong(long nb);
unsigned long long	ft_ulong_to_ullong(unsigned long nb);
unsigned long long	ft_uint_to_ullong(unsigned int nb);
long double			ft_dbl_to_longdbl(double nb);

char				*ft_int_to_str(long long nb);
char				*ft_uint_to_str(unsigned long long nb, char type);
char				*ft_longdbl_to_str(long double nb, int preci);
char				*ft_int_to_char(int nb);

unsigned long long	ft_get_addr(void *ptr);

long long			ft_get_preci(const char *format, char type);
char				*ft_get_flags(const char *format, char *str, char type);
int					ft_is_flag(char c);
long long			ft_minlen(const char *format);
char				*ft_apply_flags(t_flag *flag, char *str);

void				ft_init_light(t_flag *flag, const char *format, char type);
void				ft_set_light(t_flag *flag, const char *format);

char				*ft_apply_sharp(char *str, char type);
char				*ft_apply_sign(char *str);
char				*ft_apply_space(char *str);

char				*ft_apply_preci(long long preci, char *str, char type);
char				*ft_apply_sp_front(char *str, long long complet);
char				*ft_apply_sp_behind(char *str, long long complet);
char				*ft_apply_zero(char *str, long long complet);
#endif
