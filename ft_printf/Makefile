# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 11:24:21 by cvallejo          #+#    #+#              #
#    Updated: 2022/06/14 17:00:47 by cvallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
printf_utils.c \
print_chars.c \
print_hexa.c \
print_dec.c \

NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror
CC = gcc
AR = ar rcs
RM = rm -f

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}

all: $(NAME)
	
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re