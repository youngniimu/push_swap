#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thalme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 14:18:28 by thalme            #+#    #+#              #
#    Updated: 2020/08/12 14:18:29 by thalme           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = checker
FLAGS = -Wall -Wextra -Werror
SRC_FILES = checker.c \
			read_command.c \
			visualizer.c
			
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIB = ../libprintf
LIB_OBJ = ../libprintf/libftprintf.a
SHARED_SRC = ../shared_src
SHARED_SRC_OBJ = ../shared_src/shared_src.a



all: $(NAME)

$(NAME):
		make -C $(LIB)
		make -C $(SHARED_SRC)
		gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB_OBJ) $(SHARED_SRC_OBJ) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

clean:
		make -C	$(LIB) clean
		make -C $(SHARED_SRC) clean
fclean:
		make -C	$(LIB) fclean
		make -C $(SHARED_SRC) fclean
		rm -f $(NAME)
		
re:	fclean all