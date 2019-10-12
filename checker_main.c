/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:39:10 by astanton          #+#    #+#             */
/*   Updated: 2019/10/07 21:39:16 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static void	check_stacks(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b && *stack_b != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	*stack_b = *stack_a;
	while (*stack_b && (*stack_b)->next)
	{
		if ((*stack_b)->num > (*stack_b)->next->num)
		{
			write(1, "KO\n", 3);
			return ;
		}
		(*stack_b) = (*stack_b)->next;
	}
	write(1, "OK\n", 3);
}

static int	sort_stack(t_container *a, t_container *b, char *line)
{
	if (!ft_strcmp("sa", line))
		swap_stacks(&(a->stack), NULL);
	else if (!ft_strcmp("sb", line))
		swap_stacks(NULL, &(b->stack));
	else if (!ft_strcmp("ss", line))
		swap_stacks(&(a->stack), &(b->stack));
	else if (!ft_strcmp("ra", line))
		rotate_stacks(&(a->stack), NULL);
	else if (!ft_strcmp("rb", line))
		rotate_stacks(NULL, &(b->stack));
	else if (!ft_strcmp("rr", line))
		rotate_stacks(&(a->stack), &(b->stack));
	else if (!ft_strcmp("rra", line))
		reverse_rotate_stacks(&(a->stack), NULL);
	else if (!ft_strcmp("rrb", line))
		reverse_rotate_stacks(NULL, &(b->stack));
	else if (!ft_strcmp("rrr", line))
		reverse_rotate_stacks(&(a->stack), &(b->stack));
	else if (!ft_strcmp(line, "pa"))
		push_a(a, b);
	else if (!ft_strcmp(line, "pb"))
		push_b(a, b);
	else
		return (0);
	return (1);
}

static void	sort_and_vizual(t_container *a, t_container *b, char *line)
{
	if (!sort_stack(a, b, line))
	{
		write(1, "Error\n", 6);
		ft_free_stacks(a, b);
		free(line);
		exit(1);
	}
	if (a->print)
	{
		(!a->step) ? write(1, "\033c", 3) : write(1, "\n\n\n\n", 4);
		(a->color) ? write(1, "\x1b[34m", 6) : 0;
		write(1, line, ft_strlen(line));
		(a->color) ? write(1, "\x1b[0m", 5) : 0;
		write(1, "\n", 1);
		visual_sort(a, b);
		usleep(a->time * 100000);
	}
	free(line);
}

int			main(int ac, char **av)
{
	t_container	*a;
	t_container	*b;
	char		*line;

	if (ac == 1)
		return (0);
	if (!((b = (t_container*)malloc(sizeof(t_container))) &&
		(a = (t_container*)malloc(sizeof(t_container)))))
		exit(1);
	fill_flags(a, b, av[1]);
	if (!prepare_stack(a, ac, av))
	{
		ft_free_stacks(a, b);
		exit(0);
	}
	(a->print) ? prepare_ranks(a) : 0;
	while (get_next_line(0, &line) > 0)
		sort_and_vizual(a, b, line);
	free(line);
	check_stacks(&(a->stack), &(b->stack));
	ft_free_stacks(a, b);
	return (0);
}
