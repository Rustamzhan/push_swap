/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 00:26:15 by astanton          #+#    #+#             */
/*   Updated: 2019/10/09 00:26:17 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static int	find_min(t_stack *stack)
{
	int	min;

	min = stack->num;
	stack = stack->next;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

static int	check_stack(t_stack *stack, t_stack *a, int min)
{
	stack = a;
	while (stack->next && stack->num != min)
	{
		if (stack->num > stack->next->num && stack->next->num != min)
			return (0);
		stack = stack->next;
	}
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (a->num != min && stack->num > a->num ? 0 : 1);
}

int			is_sorted_stack(t_container *a, t_container *b)
{
	t_stack	*stack;
	int		min;

	if (b && b->height)
		return (0);
	else if (a->height < 2)
		return (2);
	else if (a->height < 3)
		return (1);
	stack = a->stack;
	min = find_min(stack);
	return (check_stack(stack, a->stack, min));
}

void		print_rotates(t_container *a)
{
	int		min;
	int		i;
	t_stack	*stack;

	min = find_min(a->stack);
	stack = a->stack;
	i = 1;
	while (stack->num != min)
	{
		i++;
		stack = stack->next;
	}
	if (a->height - i > i)
	{
		while (i--)
			write(1, "ra\n", 3);
	}
	else
	{
		i = a->height - i;
		while (i--)
			write(1, "rra\n", 4);
	}
}

int			check_position(t_stack *a)
{
	t_stack *b;

	b = a;
	while (b->next)
		b = b->next;
	return (a->num > b->num);
}
