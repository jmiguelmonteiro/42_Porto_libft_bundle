# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 13:04:36 by josemigu          #+#    #+#              #
#    Updated: 2025/04/08 15:23:10 by josemigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c
OBJS = ${SRCS:.c=.o}
OUT_FILE_NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs

RM = rm -f

all: ${OUT_FILE_NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${OUT_FILE_NAME}

re: fclean all

%.o: %.c 
	${CC} ${CFLAGS} -c $< -o $@

${OUT_FILE_NAME}: ${OBJS}
	${AR} ${OUT_FILE_NAME} ${OBJS}

main:
	${CC} ${CFLAGS} main.c libft.a -lbsd
	
.PHONY: all clean fclean re
