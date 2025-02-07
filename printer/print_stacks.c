/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 04:22:16 by astanton          #+#    #+#             */
/*   Updated: 2019/10/12 04:22:18 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static void		print_symbols(char *str, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
		write(1, str, 1);
}

static void		print_string(t_stack *a, t_stack *b, int height, int color)
{
	int		i;

	i = (a) ? a->rank : 0;
	(color) ? write(1, "\x1b[32m", 6) : 0;
	(color && a && a->marker) ? write(1, "\x1b[31m", 6) : 0;
	(a) ? a->marker = 0 : 0;
	print_symbols(" ", 5 + height - i);
	print_symbols("_", 2 * i);
	print_symbols(" ", 5 + height - i);
	i = (b) ? b->rank : 0;
	(color) ? write(1, "\x1b[33m", 6) : 0;
	(color && b && b->marker) ? write(1, "\x1b[31m", 6) : 0;
	(b) ? b->marker = 0 : 0;
	print_symbols(" ", 5 + height - i);
	print_symbols("_", 2 * i);
	(color) ? write(1, "\x1b[0m", 5) : 0;
	write(1, "\n", 1);
}

static void		print_cap(int color)
{
	(color) ? write(1, "\x1b[32m", 6) : 0;
	write(1, " ----------------", 18);
	(color) ? write(1, "\x1b[33m", 6) : 0;
	write(1, "    ----------------\n", 22);
	(color) ? write(1, "\x1b[32m", 6) : 0;
}

static void		print_numbers(t_stack *a, t_stack *b, int color)
{
	char	*num;

	num = (a) ? ft_itoa(a->num) : ft_strjoin("", "");
	print_cap(color);
	(color) ? write(1, "\x1b[32m", 6) : 0;
	write(1, "|", 1);
	print_symbols(" ", 5 + 10 - ft_strlen(num));
	(color && a && a->marker) ? write(1, "\x1b[31m", 6) : 0;
	write(1, num, ft_strlen(num));
	(color && a && a->marker) ? write(1, "\x1b[32m", 6) : 0;
	(a) ? a->marker = 0 : 0;
	free(num);
	write(1, " |  ", 5);
	(color) ? write(1, "\x1b[33m", 6) : 0;
	write(1, "|", 1);
	num = (b) ? ft_itoa(b->num) : ft_strjoin("", "");
	print_symbols(" ", 5 + 10 - ft_strlen(num));
	(color && b && b->marker) ? write(1, "\x1b[31m", 6) : 0;
	write(1, num, ft_strlen(num));
	(color && b && b->marker) ? write(1, "\x1b[33m", 6) : 0;
	(b) ? b->marker = 0 : 0;
	write(1, " |", 2);
	write(1, "\n", 1);
	print_cap(color);
	free(num);
}

void			visual_sort(t_container *stack_a, t_container *stack_b)
{
	t_stack *a;
	t_stack *b;

	a = stack_a->stack;
	b = stack_b->stack;
	while (a || b)
	{
		if (stack_a->text)
			print_numbers(a, b, stack_a->color);
		else
			print_string(a, b, stack_a->amount_of_nums, stack_a->color);
		a = (a) ? a->next : NULL;
		b = (b) ? b->next : NULL;
	}
}
