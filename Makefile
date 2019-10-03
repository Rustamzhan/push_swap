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

SRCS_1 = ./commands/push.c ./commands/reverse_rotate.c ./commands/rotate.c\
		./commands/swap.c ./stack/validator.c ./stack/prepare_int_array.c\
		./stack/prepare_stack.c ./main.c

SRCS_2 = ./commands/push.c ./commands/reverse_rotate.c ./commands/rotate.c\
		./commands/swap.c ./stack/validator.c ./stack/prepare_int_array.c\
		./stack/prepare_stack.c

OBJ_1 =  ./commands/push.o ./commands/reverse_rotate.o ./commands/rotate.o\
		./commands/swap.o ./stack/validator.o ./stack/prepare_int_array.o\
		./stack/prepare_stack.o ./main.o

HDR = ./libft/includes/

FLAG = -Wall -Wextra -Werror

all: $(NAME_1)

$(NAME_1): $(OBJ_1)
	make -C libft
	gcc -o $(NAME_1) $(OBJ_1) -L ./libft -lft

$(OBJ_1): %.o: %.c ./ft_swap_header.h
	
	gcc $(FLAG) -c -I $(HDR) -I . $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJ_1)

fclean: clean
	make -C libft fclean
	rm -f $(NAME_1)

re: fclean all
