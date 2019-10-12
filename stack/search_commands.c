/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 02:26:40 by astanton          #+#    #+#             */
/*   Updated: 2019/10/10 02:26:43 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static t_commands	find_direction(t_commands table, int pos_b, int height_a,
							int height_b)
{
	if (height_a - table.position_in_a > table.position_in_a)
	{
		table.tra = table.position_in_a;
		table.str_a = "ra\n";
	}
	else
	{
		table.tra = height_a - table.position_in_a;
		table.str_a = "rra\n";
	}
	if (height_b - pos_b > pos_b)
	{
		table.trb = pos_b;
		table.str_b = "rb\n";
	}
	else
	{
		table.trb = height_b - pos_b;
		table.str_b = "rrb\n";
	}
	table.trr = 0;
	return (table);
}

static t_commands	check_direction(t_commands table, int height_a,
									int height_b)
{
	if ((!ft_strcmp(table.str_a, "ra\n") && !ft_strcmp(table.str_b, "rb\n"))
	|| (!ft_strcmp(table.str_a, "rra\n") && !ft_strcmp(table.str_b, "rrb\n")))
	{
		table.trr = (table.tra < table.trb) ? table.tra : table.trb;
		table.str_both = (ft_strcmp("ra\n", table.str_a)) ? "rrr\n" : "rr\n";
		table.tra -= table.trr;
		table.trb -= table.trr;
	}
	else if (table.tra > height_b && height_b > 1)
	{
		table.trr = ft_strcmp("rb\n", table.str_a) ? height_b - table.trb :
			table.trb;
		table.str_both = ft_strcmp("ra\n", table.str_a) ? "rrr\n" : "rr\n";
		table.trb = 0;
		table.tra -= table.trr;
	}
	else if (table.trb > height_a && height_a > 1)
	{
		table.trr = ft_strcmp("rb\n", table.str_b) ? height_a - table.tra :
			table.tra;
		table.str_both = ft_strcmp("rb\n", table.str_b) ? "rrr\n" : "rr\n";
		table.tra = 0;
		table.trb -= table.trr;
	}
	return (table);
}

t_commands			fill_score_table(t_commands table, int pos_b, int height_a,
							int height_b)
{
	table = find_direction(table, pos_b, height_a, height_b);
	table = check_direction(table, height_a, height_b);
	table.summ_tr = table.tra + table.trb + table.trr;
	if (table.summ > table.summ_tr || !table.check)
	{
		table.ra = table.tra;
		table.rb = table.trb;
		table.rr = table.trr;
		table.r_str_a = table.str_a;
		table.r_str_b = table.str_b;
		table.r_str_both = table.str_both;
		table.summ = table.summ_tr;
	}
	table.check = 1;
	return (table);
}

int					find_position(t_stack *stack, int num)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	if (stack->num > num && tmp->num < num)
		return (i);
	i++;
	while (stack->next && !(stack->num < num && stack->next->num > num) &&
		!(stack->num > num && stack->next->num > num &&
			stack->num > stack->next->num))
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
