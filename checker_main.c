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
	if (*stack_b != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	*stack_b = *stack_a;
	while ((*stack_b)->next)
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
		return (1);
	return (0);
}

static void	vizual_sort(t_container *stack_a, t_container *stack_b)
{
	char	*str;
	char	*num1;
	char	*num2;
	t_stack *a;
	t_stack *b;

	a = stack_a->stack;
	b = stack_b->stack;
	while (a || b)
	{
		num1 = (a) ? ft_strjoin(ft_itoa(a->num), ft_strjoin("|", ft_itoa(stack_a->height))) : ft_strjoin("", "");
		num2 = (b) ? ft_strjoin(ft_itoa(b->num), ft_strjoin("|", ft_itoa(stack_b->height))) : ft_strjoin("", "");
		str = ft_strjoin(num1, ft_strjoin(ft_strjoin("	", num2), "\n"));
		write(1, str, ft_strlen(str));
		
		free(num1);
		free(num2);
		free(str);
		a = (a) ? a->next : NULL;
		b = (b) ? b->next : NULL;
	}
	write(1, "\n\n", 2);
	//sleep(3);
	//write(1, "\033c", 3);
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

static void	sort_and_vizual(t_container *a, t_container *b, char *line,
							char *arg)
{
	if (sort_stack(a, b, line))
	{
		write(1, "Error\n", 6);
		ft_free_stacks(a, b);
		free(line);
		exit(1);
	}
	free(line);
	(!ft_strcmp("-v", arg)) ? write(1, line, ft_strlen(line)) : 0;
	(!ft_strcmp("-v", arg)) ? write(1, "\n", 1) : 0;
	(!ft_strcmp("-v", arg)) ? vizual_sort(a, b) : 0;
}

int			main(int ac, char **av)
{
	t_container	*a;
	t_container	*b;
	char	*line;

	if (ac == 1 || (ac == 2 && ft_strcmp("-v", av[1]) == 0))
		return (0);
	if (!(b = (t_container*)malloc(sizeof(t_container))) ||
		!(a = (t_container*)malloc(sizeof(t_container))))
		exit(1);
	b->height = 0;
	b->stack = NULL;
	prepare_stack(a, ac, av);
	if (a->stack == NULL)
		return (0);
	while (get_next_line(0, &line) > 0)
		sort_and_vizual(a, b, line, av[1]);
	free(line);
	check_stacks(&(a->stack), &(b->stack));
	ft_free_stacks(a, b);
	return (0);
}
