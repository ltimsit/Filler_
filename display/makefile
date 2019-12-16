# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 13:00:42 by ltimsit-          #+#    #+#              #
#    Updated: 2019/07/08 18:53:43 by ltimsit-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = display_filler
SRCS = display.c utils.c get_player_and_win.c screen_info.c \
	   hook.c init_data.c calc_map.c
INCLUDE = -I ../include
LIBFT = ../libft/libft.a
LIBFTPRINTF = ../libftprintf.a
LIBMLX = libmlx.a
OSRCS = $(SRCS:.c=.o)
FLAGS = -c -Wall -Wextra -Werror 
CC = gcc $(INCLUDE)
FRAMEWORKS = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OSRCS) Makefile
	make -C ../libft
	gcc $(FLAGS) $(SRCS) $(INCLUDE) 
	gcc $(OSRCS) -o $(NAME) $(LIBFT) $(LIBFTPRINTF) $(LIBMLX) $(FRAMEWORKS)
	@./snap.sh

snap :
	@./snap.sh

clean :
	rm -rf $(OSRCS)
	make clean -C ../libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C ../libft

re : fclean all

.PHONY : clean fclean re all
