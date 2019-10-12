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
# include <time.h>

typedef struct			s_stack
{
	int					num;
	int					rank;
	struct s_stack		*prev;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_container
{
	t_stack				*stack;
	int					amount_of_nums;
	int					height;
	int					step;
	int					print;
}						t_container;

typedef struct			s_commands
{
	int					check;
	int					rb;
	int					ra;
	int					rr;
	int					summ;
	int					position_in_a;
	int					trr;
	int					tra;
	int					trb;
	int					summ_tr;
	char				*r_str_both;
	char				*r_str_a;
	char				*r_str_b;
	char				*str_both;
	char				*str_a;
	char				*str_b;
}						t_commands;

int						ft_check_duplicates(int *result);
int						ft_isint(char *str);
int						ft_isnumber(char *str);
int						ft_check_command(char *str);
int						*prepare_array_of_numbers(t_container *a, int ac,
													char **av);
int						is_sorted_stack(t_container *a, t_container *b);
int						check_position(t_stack *a);
int						find_position(t_stack *stack, int num);
int						prepare_stack(t_container *a, int ac, char **av);
int						fill_flags(t_container *a, t_container *b, char *arg);
void					prepare_ranks(t_container *a, char *arg);
void					visual_sort(t_container *stack_a, t_container *stack_b);
void					print_rotates(t_container *a);
void					swap_stacks(t_stack **a, t_stack **b);
void					push_a(t_container *a, t_container *b);
void					push_b(t_container *a, t_container *b);
void					rotate_stacks(t_stack **a, t_stack **b);
void					reverse_rotate_stacks(t_stack **a, t_stack **b);
void					ft_free_stacks(t_container *a, t_container *b);
t_commands				fill_score_table(t_commands table, int pos_b,
										int height_a, int height_b);

#endif
