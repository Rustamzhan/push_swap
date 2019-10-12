/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 02:18:17 by astanton          #+#    #+#             */
/*   Updated: 2019/10/10 02:18:25 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static t_commands	clean_struct(t_commands score)
{
	score.check = 0;
	score.ra = 0;
	score.rb = 0;
	score.rr = 0;
	score.summ = 0;
	score.position_in_a = 0;
	score.trr = 0;
	score.tra = 0;
	score.trb = 0;
	score.summ_tr = 0;
	return (score);
}

static void			print_commands(t_container *a, t_container *b,
									t_commands table)
{
	while (table.rr--)
	{
		write(1, table.r_str_both, ft_strlen(table.r_str_both));
		(ft_strcmp("rrr\n", table.r_str_both)) ? rotate_stacks(&(a->stack),
			&(b->stack)) : reverse_rotate_stacks(&(a->stack), &(b->stack));
	}
	while (table.ra--)
	{
		write(1, table.r_str_a, ft_strlen(table.r_str_a));
		(ft_strcmp("rra\n", table.r_str_a)) ? rotate_stacks(&(a->stack), NULL) :
			reverse_rotate_stacks(&(a->stack), NULL);
	}
	while (table.rb--)
	{
		write(1, table.r_str_b, ft_strlen(table.r_str_b));
		(ft_strcmp("rrb\n", table.r_str_b)) ? rotate_stacks(NULL, &(b->stack)) :
			reverse_rotate_stacks(NULL, &(b->stack));
	}
}

static void			sort_two_stacks(t_container *a, t_container *b)
{
	t_commands	score;
	t_stack		*tmp;
	int			i;

	while (b->stack)
	{
		score = clean_struct(score);
		i = 0;
		tmp = b->stack;
		while (tmp)
		{
			score.position_in_a = find_position(a->stack, tmp->num);
			score = fill_score_table(score, i, a->height, b->height);
			tmp = tmp->next;
			i++;
		}
		print_commands(a, b, score);
		write(1, "pa\n", 3);
		push_a(a, b);
	}
}

static void			search_solve(t_container *a, t_container *b)
{
	while (!is_sorted_stack(a, NULL) && a->height > 3)
	{
		if (check_position(a->stack))
		{
			write(1, "ra\n", 3);
			rotate_stacks(&a->stack, NULL);
		}
		else
		{
			write(1, "pb\n", 3);
			push_b(a, b);
		}
	}
	if (a->height == 3 && !is_sorted_stack(a, NULL))
	{
		write(1, "sa\n", 3);
		swap_stacks(&(a->stack), NULL);
	}
	sort_two_stacks(a, b);
}

int					main(int ac, char **av)
{
	t_container	*a;
	t_container	*b;

	if (ac == 1)
		return (0);
	if (!((b = (t_container*)malloc(sizeof(t_container))) &&
		(a = (t_container*)malloc(sizeof(t_container)))))
		exit(1);
	b->height = 0;
	b->stack = NULL;
	a->print = 0;
	if (!prepare_stack(a, ac, av) || is_sorted_stack(a, b) == 2)
	{
		ft_free_stacks(a, b);
		exit(0);
	}
	else if (!is_sorted_stack(a, b))
		search_solve(a, b);
	print_rotates(a);
	ft_free_stacks(a, b);
	return (0);
}
