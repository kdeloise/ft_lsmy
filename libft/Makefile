# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 17:58:13 by kdeloise          #+#    #+#              #
#    Updated: 2019/10/23 16:25:18 by kdeloise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = gcc -Wall -Wextra -Werror

HEADER = *.h

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	ft_strdel.c ft_strnew.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_strndup.c ft_cntword.c ft_lennbr.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_cspec.c ft_itoa_base.c ft_fillta.c ft_printf.c ft_flag.c \
	ft_flags.c ft_flagsproc.c ft_procspec.c ft_xoxspec.c ft_uspec.c \
	ft_color.c ft_rspec.c dtoa.c ft_fspec.c ft_fflag.c ft_flag2.c ft_flags2.c \
	ft_fflag2.c ft_flag3.c ft_procspec2.c ft_rspec2.c ft_lennbrdiuxox.c \
	ft_flags3.c ft_pricont.c ft_pricont2.c ft_dispec.c ft_lastlenfl.c ft_lnh.c
OBJ = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o \
	ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o \
	ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o \
	ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o \
	ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
	ft_isprint.o ft_toupper.o ft_tolower.o ft_memalloc.o ft_memdel.o \
	ft_strdel.o ft_strnew.o ft_strclr.o ft_striter.o ft_striteri.o \
	ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o \
	ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o \
	ft_putstr.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o \
	ft_putendl_fd.o ft_putnbr_fd.o ft_strndup.o ft_cntword.o ft_lennbr.o \
	ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
	ft_cspec.o ft_itoa_base.o ft_fillta.o ft_printf.o ft_flag.o \
	ft_flags.o ft_flagsproc.o ft_procspec.o ft_xoxspec.o ft_uspec.o \
	ft_color.o ft_rspec.o dtoa.o ft_fspec.o ft_fflag.o ft_flag2.o ft_flags2.o \
	ft_fflag2.o ft_flag3.o ft_procspec2.o ft_rspec2.o ft_lennbrdiuxox.o \
	ft_flags3.o ft_pricont.o ft_pricont2.o ft_dispec.o ft_lastlenfl.o ft_lnh.o

all: $(NAME)

$(NAME):
	$(FLAGS) -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all