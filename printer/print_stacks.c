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

static void		print_string(t_stack *a, t_stack *b, int height)
{
	char	*num;
	int		i;

	num = (a) ? ft_itoa(a->num) : ft_strjoin("", "");
	i = (a) ? a->rank : 0;
	write(1, "\x1b[32m", 6);
	print_symbols(" ", 5 + height - i);
	print_symbols("_", i);
	print_symbols("_", i);
	print_symbols(" ", 5 + height - i);
	write(1, "\x1b[0m", 5);
	i = (b) ? b->rank : 0;
	write(1, "\x1b[31m", 6);
	print_symbols(" ", 5 + height - i);
	print_symbols("_", i);
	free(num);
	num = (b) ? ft_itoa(b->num) : ft_strjoin(" ", "");
	print_symbols("_", i);
	write(1, "\x1b[0m", 5);
	write(1, "\n", 1);
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
		print_string(a, b, stack_a->amount_of_nums);
		a = (a) ? a->next : NULL;
		b = (b) ? b->next : NULL;
	}
}
