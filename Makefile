#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thalme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/12 14:16:08 by thalme            #+#    #+#              #
#    Updated: 2020/08/12 14:16:09 by thalme           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

$(NAME) : all

all:
	make -C checker_dir
	cp checker_dir/checker .
	make -C push_swap_dir
	cp push_swap_dir/push_swap .

clean:
	make -C checker_dir clean
	make -C push_swap_dir clean

fclean:
	make -C checker_dir fclean
	make -C push_swap_dir fclean
	rm -f checker
	rm -f push_swap

re: fclean all