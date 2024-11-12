# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 18:32:45 by ruida-si          #+#    #+#              #
#    Updated: 2024/11/09 18:35:50 by ruida-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = get_next_line_bonus.c get_next_line_utils_bonus.c

ap:
	$(CC) $(FLAGS) $(SRC)
	./a.out
