/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:18:55 by astanton          #+#    #+#             */
/*   Updated: 2019/10/01 15:18:57 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SWAP_HEADER_H
# define FT_SWAP_HEADER_H

# include "libft.h"
# include <stdio.h>
# include <time.h>
# include <mlx.h>

typedef struct			s_stack
{
	int					num;
	struct s_stack		*prev;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_commands
{
	char				*command;
	struct s_commands	*next;
}						t_commands;

int						ft_check_duplicates(int *result);
int						ft_isint(char *str);
int						ft_isnumber(char *str);
int						ft_check_command(char *str);
int						*prepare_array_of_numbers(int ac, char **av);
t_stack					*prepare_stack(int ac, char **av);
void					swap_stacks(t_stack **a, t_stack **b);
void					push_a(t_stack **a, t_stack **b);
void					push_b(t_stack **a, t_stack **b);
void					rotate_stacks(t_stack **a, t_stack **b);
void					reverse_rotate_stacks(t_stack **a, t_stack **b);

#endif
