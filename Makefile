# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 15:01:28 by raphox            #+#    #+#              #
#    Updated: 2024/09/10 17:09:23 by rafaria          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

SRCS			=	pipex.c tools.c split.c

OBJS			=	${SRCS:.c=.o}

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra -g3

LIBFT_DIR	=	libft

LIBFT_LIB	=	$(LIBFT_DIR)

all			:	${NAME}

$(NAME): $(OBJS) $(LIBFT_LIB)
	make -C ${LIBFT_DIR}
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean			:
	rm -rf ${OBJS}
	make -C ${LIBFT_DIR} clean

fclean			:	clean
	rm -rf ${NAME}
	make -C ${LIBFT_DIR} fclean

re				:	fclean all

.PHONY			:	all clean fclean re