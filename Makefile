# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 15:23:04 by hroh              #+#    #+#              #
#    Updated: 2020/10/08 16:32:49 by hroh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = ft_calloc.c ft_isascii.c ft_isspace.c ft_memccpy.c ft_memcpy.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcpy.c ft_strncmp.c \
		ft_strtrim.c ft_toupper.c ft_atoi.c ft_isalnum.c ft_isdigit.c \
		ft_itoa.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_split.c \
		ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c ft_bzero.c \
		ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c \
		ft_strchr.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(FILES))
OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(subst .c,.o,$(SRCS)))


.c.o: $(SRCS)
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		$(AR) $@ $^

all: $(NAME)

clean: 
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re