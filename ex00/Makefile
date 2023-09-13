# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 21:15:08 by ccompote          #+#    #+#              #
#    Updated: 2023/09/05 17:07:40 by ccompote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

SRCS =  main.cpp  BitcoinExchange.cpp

NAME =  btc

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = ./obj/
OBJ_FILES = $(patsubst %.cpp, %.o, $(SRCS))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRCS_DIR = ./

$(OBJ_DIR)%.o:$(SRCS_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: obj $(NAME)

obj: 
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re