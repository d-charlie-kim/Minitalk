# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 14:45:19 by dokkim            #+#    #+#              #
#    Updated: 2021/07/06 14:45:20 by dokkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

NAME_SERVER = server
NAME_CLIENT = client

# BONUS_NAME_SERVER = server_bonus
# BONUS_NAME_CLIENT = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_SERVER = ./server.c \
				utils.c

SRCS_CLIENT = ./client.c \
				utils.c

# BONUS_SRCS_SERVER = ./bonus/server.c \
# 					./bonus/utils.c
# BONUS_SRCS_CLIENT = ./bonus/client.c \
# 					./bonus/utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# BONUS_OBJS_SERVER = $(BONUS_SRCS_SERVER:.c=.o)
# BONUS_OBJS_CLIENT = $(BONUS_SRCS_CLIENT:.c=.o)

$(NAME_SERVER) : $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

# $(BONUS_NAME_SERVER) : $(BONUS_OBJS_SERVER)
# 	$(CC) $(CFLAGS) $(BONUS_OBJS_SERVER) -o $(BONUS_NAME_SERVER)
# $(BONUS_NAME_CLIENT) : $(BONUS_OBJS_CLIENT)
# 	$(CC) $(CFLAGS) $(BONUS_OBJS_SERVER) -o $(BONUS_NAME_CLIENT)

all : $(NAME_SERVER) $(NAME_CLIENT)

clean :
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean : clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT)

bonus : all $(BONUS_SERVER) $(BONUS_CLIENT)

re : fclean all

.PHONY : all clean fclean re bonus