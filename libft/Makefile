# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:27:32 by jdias-mo          #+#    #+#              #
#    Updated: 2022/05/15 17:06:52 by jdias-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strlen.c ft_itoa.c ft_substr.c ft_strjoin.c  ft_split.c ft_strdup.c \
			get_next_line.c ft_printf.c ft_printf_utils.c ft_printf_utils_aux.c

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
		${RM} ${NAME}

rebonus:	fclean bonus

re:		fclean all

.PHONY : all clean fclean re
