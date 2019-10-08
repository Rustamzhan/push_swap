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

static void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
	while (stack_b)
	{
		tmp = stack_b->next;
		free(stack_b);
		stack_b = tmp;
	}
}

static void	check_stacks(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b != NULL)
	{
		free_stacks(*stack_a, *stack_b);
		write(1, "KO\n", 3);
		exit(0);
	}
	*stack_b = *stack_a;
	while ((*stack_b)->next)
	{
		if ((*stack_b)->num > (*stack_b)->next->num)
		{
			free_stacks(*stack_a, NULL);
			write(1, "KO\n", 3);
			exit(0);
		}
		(*stack_b) = (*stack_b)->next;
	}
	write(1, "OK\n", 3);
	free_stacks(*stack_a, NULL);
}

static int	sort_stack(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strcmp("sa", line))
		swap_stacks(stack_a, NULL);
	else if (!ft_strcmp("sb", line))
		swap_stacks(NULL, stack_b);
	else if (!ft_strcmp("ss", line))
		swap_stacks(stack_a, stack_b);
	else if (!ft_strcmp("ra", line))
		rotate_stacks(stack_a, NULL);
	else if (!ft_strcmp("rb", line))
		rotate_stacks(NULL, stack_b);
	else if (!ft_strcmp("rr", line))
		rotate_stacks(stack_a, stack_b);
	else if (!ft_strcmp("rra", line))
		reverse_rotate_stacks(stack_a, NULL);
	else if (!ft_strcmp("rrb", line))
		reverse_rotate_stacks(NULL, stack_b);
	else if (!ft_strcmp("rrr", line))
		reverse_rotate_stacks(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa"))
		push_a(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb"))
		push_b(stack_a, stack_b);
	else
		return (1);
	return (0);
}

static void	vizual_sort(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;
	char	*num1;
	char	*num2;

	while (stack_a || stack_b)
	{
		num1 = (stack_a) ? ft_itoa(stack_a->num) : ft_strjoin("", "");
		num2 = (stack_b) ? ft_itoa(stack_b->num) : ft_strjoin("", "");
		str = ft_strjoin(num1, ft_strjoin(ft_strjoin("	", num2), "\n"));
		write(1, str, ft_strlen(str));
		free(num1);
		free(num2);
		free(str);
		stack_a = (stack_a) ? stack_a->next : NULL;
		stack_b = (stack_b) ? stack_b->next : NULL;
	}
	sleep(3);
	write(1, "\033c", 3);
}

// void	mlx_visual_try(t_stack *stack_a, t_stack *stack_b)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	((mlx_ptr = mlx_init())) ? 0 : exit(1);
// 	((win_ptr = mlx_new_window(mlx_ptr, 1300, 1300, "AmazinG"))) ? 0 :
// 								exit(1);
// 	if (stack_a && stack_b)
// 		;
// 	mlx_loop(mlx_ptr);
// }

int			main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	if (ac == 1 || (ac == 2 && ft_strcmp("-v", av[1]) == 0))
		return (0);
	stack_a = prepare_stack(ac, av);
	if (stack_a == NULL)
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		if (sort_stack(&stack_a, &stack_b, line))
		{
			write(1, "Error\n", 6);
			free_stacks(stack_a, stack_b);
			free(line);
			exit(1);
		}
		free(line);
		(ft_strcmp("-v", av[1]) == 0) ? vizual_sort(stack_a, stack_b) : 0;
	}
	free(line);
	check_stacks(&stack_a, &stack_b);
	return (0);
}
