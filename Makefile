# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 00:32:07 by marcgar2          #+#    #+#              #
#    Updated: 2024/12/27 00:32:07 by marcgar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
SRCS = src/main.c \
	src/push.c \
	src/k_sort.c \
	src/reverseRotate.c \
	src/rotate.c \
	src/sort.c \
	src/swap.c \
	utils/check_args.c \
	utils/index.c \
	utils/libft_files.c \
	utils/lists.c \
	utils/utils.c
OBJS = ${SRCS:.c=.o}
LIBFT_DIR = ./libft
LIBFT = {LIBFT_DIR}/libft.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

clean:
	${MAKE} -C ${LIBFT_DIR} fclean
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
