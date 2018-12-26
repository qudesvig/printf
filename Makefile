# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 14:02:36 by qudesvig          #+#    #+#              #
#    Updated: 2018/12/17 18:56:28 by qudesvig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS_NAME = ft_printf.c \
			ft_types.c \
			ft_params.c \
			ft_cast.c \
			ft_int.c \
			ft_unint.c \
			ft_double.c \
			ft_ptr.c \
			ft_flags.c \
			ft_light.c \
			ft_apply.c \
			ft_apply2.c

LIB_OBJS = 	libft/ft_atoi.o \
			libft/ft_bzero.o \
			libft/ft_convert_base.o \
			libft/ft_putstr.o \
			libft/get_next_line.o \
			libft/ft_strcat.o \
			libft/ft_strdel.o \
			libft/ft_strdup.o \
			libft/ft_strjoin.o \
			libft/ft_strlen.o \
			libft/ft_strnew.o \
			libft/ft_itoa.o \
			libft/ft_lensplit.o \
			libft/ft_memdel.o \
			libft/ft_memset.o \
			libft/ft_strncat.o \
			libft/ft_strncpy.o \
			libft/ft_putendl.o \
			libft/ft_putnbr.o \
			libft/ft_putchar.o \
			libft/ft_realloc.o \
			libft/ft_strcpy.o \
			libft/ft_isdigit.o

SRCS_PATH = srcs/

INC = includes/ft_printf.h \
	  libft/includes/libft.h \
	  libft/includes/get_next_line.h

LIBNAME = libft.a

LIB_PATH = libft/

LIB = $(addprefix $(LIB_PATH), $(LIBNAME))

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = $(SRCS_NAME:%.c=%.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) $(LIB_OBJS)
	ranlib $(NAME)

$(OBJS): $(SRCS) $(LIB) $(INC)
	$(CC) $(FLAGS) -c $(SRCS)
	make -C $(LIB_PATH)

$(LIB):
	make -C $(LIB_PATH)

clean:
	make -C $(LIB_PATH) clean
	rm -rf $(OBJS)

fclean : clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)

re : fclean all
	make -C $(LIB_PATH) re
