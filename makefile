# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 13:00:42 by ltimsit-          #+#    #+#              #
#    Updated: 2019/07/07 18:42:37 by ltimsit-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ltimsit-.filler
MAP_GEN = map_gen
SRCS = main.c map.c piece.c heat_map.c heat_tools.c error.c check_map.c
MAP_DIR = map_generator/
MAPSRCS = map_gen.c
CMAPSRCS = $(addprefix $(MAP_DIR), $(MAPSRCS))
INCLUDE = -I include
LIBFT = libft/libft.a
LIBFTPRINTF = libftprintf.a
OSRCS = $(SRCS:.c=.o)
OMAPSRCS = $(MAPSRCS:.c=.o)
FLAGS = -c -Wall -Wextra -Werror 
CC = gcc $(INCLUDE)

all : makelib $(NAME) $(MAP_GEN) 
makelib :
	make -C libft
	make -C display

$(NAME) : $(OSRCS) Makefile
	gcc $(FLAGS) $(SRCS) $(INCLUDE) 
	gcc $(OSRCS) -o $(NAME) $(LIBFT) $(LIBFTPRINTF)

$(OMAPSRCS) : $(CMAPSRCS)
	gcc $(FLAGS) $(CMAPSRCS) $(INCLUDE) 

$(MAP_GEN) : $(OMAPSRCS)
	make -C libft
	gcc $(OMAPSRCS) -o $(MAP_GEN) $(LIBFT) $(LIBFTPRINTF)

clean :
	rm -rf $(OSRCS) $(OMAPSRCS)
	make clean -C libft

fclean : clean
	rm -rf $(NAME) $(MAP_GEN)
	make fclean -C libft
	make fclean -C display

re : fclean all

.PHONY : clean fclean re all

