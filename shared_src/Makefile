#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thalme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 16:27:47 by thalme            #+#    #+#              #
#    Updated: 2020/08/13 16:27:47 by thalme           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = shared_src.a
SRCS = sa.c sb.c ss.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c read_input.c
OBJECTS = $(SRCS:.c=.o)
FLAGS = -Werror -Wall -Wextra

$(NAME): all

all:
	gcc -c $(FLAGS) $(SRCS)
	ar cr $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

cleandup:
	find . -type f -name '*~' -exec rm -rf {} \;