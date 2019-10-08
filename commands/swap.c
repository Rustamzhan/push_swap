/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:27:00 by astanton          #+#    #+#             */
/*   Updated: 2019/10/03 15:27:02 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static void	swap_one_stack(t_stack **current)
{
	t_stack	*tmp;

	if ((*current)->next == NULL)
		return ;
	tmp = (*current)->next;
	(*current)->next = tmp->next;
	(*current)->prev = tmp;
	tmp->prev = NULL;
	tmp->next = *current;
	*current = tmp;
}

void		swap_stacks(t_stack **a, t_stack **b)
{
	if (a && b)
	{
		if (*a)
			swap_one_stack(a);
		if (*b)
			swap_one_stack(b);
	}
	else if (a == NULL && *b)
		swap_one_stack(b);
	else if (b == NULL && *a)
		swap_one_stack(a);
}
