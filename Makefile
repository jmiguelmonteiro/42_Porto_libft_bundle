# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 13:04:36 by josemigu          #+#    #+#              #
#    Updated: 2025/05/17 13:31:36 by josemigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color codes
RED    = 	\033[0;31m
GREEN  = 	\033[0;32m
ORANGE = 	\033[0;33m
BLUE   = 	\033[34m
PURPLE = 	\033[35m
RESET  = 	\033[0m

NAME = libft.a

# Paths
GNL_DIR = gnl
PRINTF_DIR = printf
INCLUDES = -Iincludes -I$(GNL_DIR) -I$(PRINTF_DIR)

# Sources
SRCS_LIBFT = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRCS_GNL = $(GNL_DIR)/get_next_line_bonus.c

# Objects
OBJS_LIBFT = ${SRCS_LIBFT:.c=.o}
OBJS_GNL = ${SRCS_GNL:.c=.o}
OBJS_PRINTF = ${SRCS_PRINTF:.c=.o}
OBJS = $(OBJS_LIBFT) $(OBJS_GNL) $(OBJS_PRINTF)

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -g
AR = ar crs
RM = rm -f

all: ${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

%.o: %.c 
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
	@echo "✅ Libft criada com sucesso."

.PHONY: all clean fclean re
