/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:39:33 by astanton          #+#    #+#             */
/*   Updated: 2019/10/03 15:39:35 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static void	rotate_one_stack(t_stack **current)
{
	t_stack	*last;
	t_stack	*head;

	if ((*current)->next == NULL)
		return ;
	head = (*current)->next;
	last = *current;
	while (last->next)
		last = last->next;
	last->next = *current;
	(*current)->next = NULL;
	(*current)->prev = last;
	*current = head;
	(*current)->prev = NULL;
}

void		rotate_stacks(t_stack **a, t_stack **b)
{
	if (a && b)
	{
		if (*a)
			rotate_one_stack(a);
		if (*b)
			rotate_one_stack(b);
	}
	else if (a == NULL && *b)
		rotate_one_stack(b);
	else if (b == NULL && *a)
		rotate_one_stack(a);
}
