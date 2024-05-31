# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 12:39:56 by pitroin           #+#    #+#              #
#    Updated: 2024/05/30 11:41:55 by pitroin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
CLIENT_BONUS = client_bonus
SERVER = server
SERVER_BONUS = server_bonus

CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(PRINTF_DIR)

all: $(PRINTF_LIB) $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) -L$(PRINTF_DIR) -lftprintf

$(SERVER): $(SERVER_OBJ) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) -L$(PRINTF_DIR) -lftprintf

$(CLIENT_OBJ): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -c $(CLIENT_SRC)

$(SERVER_OBJ): $(SERVER_SRC)
	$(CC) $(CFLAGS) -c $(SERVER_SRC)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

#bonus
CLIENT_SRC_BONUS = client_bonus.c
SERVER_SRC_BONUS = server_bonus.c

CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)
SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)

$(CLIENT_BONUS): $(CLIENT_OBJ_BONUS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_OBJ_BONUS) -L$(PRINTF_DIR) -lftprintf

$(SERVER_BONUS): $(SERVER_OBJ_BONUS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_OBJ_BONUS) -L$(PRINTF_DIR) -lftprintf

$(CLIENT_OBJ_BONUS): $(CLIENT_SRC_BONUS)
	$(CC) $(CFLAGS) -c $(CLIENT_SRC_BONUS)

$(SERVER_OBJ_BONUS): $(SERVER_SRC_BONUS)
	$(CC) $(CFLAGS) -c $(SERVER_SRC_BONUS)

bonus: $(PRINTF_LIB) $(CLIENT_BONUS) $(SERVER_BONUS)

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
