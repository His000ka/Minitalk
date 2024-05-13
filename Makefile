# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 12:39:56 by pitroin           #+#    #+#              #
#    Updated: 2024/05/13 14:47:07 by pitroin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = serveur

PRINTF = ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I include

SRCS = serveur.c
OBJS = ${SRCS:.c=.o}

# .c.o:
# 	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAMES) = $(OBJS)
		@make -C ft_printf
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(PRINTF) -o $(NAMES)

all: $(NAMES)

clean:
	@make clean -C ft_printf
	rm -f ${OBJS}

fclean: clean
	@make fclean -C ft_printf
	rm -f ${NAMES}

re: fclean all

.PHONY: all clean fclean re