/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:49:15 by astanton          #+#    #+#             */
/*   Updated: 2019/10/03 15:49:17 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static void	reverse_rotate_one_stack(t_stack **current)
{
	t_stack	*last;

	if ((*current)->next == NULL)
		return ;
	last = *current;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	(*current)->prev = last;
	last->next = *current;
	last->prev = NULL;
	*current = last;
	(*current)->marker = 1;
}

void		reverse_rotate_stacks(t_stack **a, t_stack **b)
{
	if (a && b)
	{
		if (*a)
			reverse_rotate_one_stack(a);
		if (*b)
			reverse_rotate_one_stack(b);
	}
	else if (a == NULL && *b)
		reverse_rotate_one_stack(b);
	else if (b == NULL && *a)
		reverse_rotate_one_stack(a);
}
