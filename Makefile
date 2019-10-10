# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astanton <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 16:12:01 by astanton          #+#    #+#              #
#    Updated: 2019/10/03 16:12:03 by astanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = checker

NAME_2 = push_swap

SRC = ./checker_main.c

SRCS_1 = ./commands/push.c ./commands/reverse_rotate.c ./commands/rotate.c\
		./commands/swap.c ./stack/validator.c ./stack/prepare_int_array.c\
		./stack/prepare_stack.c

SRCS_2 = ./stack/check_condition.c ./stack/search_commands.c ./ft_push_swap.c

OBJ = ./checker_main.o

OBJ_1 =  ./commands/push.o ./commands/reverse_rotate.o ./commands/rotate.o\
		./commands/swap.o ./stack/validator.o ./stack/prepare_int_array.o\
		./stack/prepare_stack.o

OBJ_2 = ./stack/check_condition.o ./stack/search_commands.o ./ft_push_swap.o

HDR = ./libft/includes/

FLAG = -Wall -Wextra -Werror

#MINILIB = -L ./minilibx/ -lmlx -framework OpenGL -framework AppKit


all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_1) $(OBJ)
	make -C libft
	gcc -o $(NAME_1) $(OBJ) $(OBJ_1) -L ./libft -lft

$(OBJ): %.o: %.c ./ft_swap_header.h
	gcc $(FLAG) -c -I $(HDR) -I . $< -o $@

$(OBJ_1): %.o: %.c ./ft_swap_header.h
	gcc $(FLAG) -c -I $(HDR) -I . $< -o $@

$(NAME_2): $(OBJ_2) $(OBJ_1)
	make -C libft
	gcc -o $(NAME_2) $(OBJ_1) $(OBJ_2) -L ./libft -lft
	
$(OBJ_2): %.o: %.c ./ft_swap_header.h
	gcc $(FLAG) -c -I $(HDR) -I . $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJ)
	rm -f $(OBJ_1)
	rm -f $(OBJ_2)

fclean: clean
	make -C libft fclean
	rm -f $(NAME_1)
	rm -f $(NAME_2)

re: fclean all
