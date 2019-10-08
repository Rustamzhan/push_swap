/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:27:58 by astanton          #+#    #+#             */
/*   Updated: 2019/10/03 15:28:00 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b)->next;
	if (!(*a))
	{
		*a = *b;
		(*a)->next = NULL;
	}
	else
	{
		(*b)->next = *a;
		(*a)->prev = *b;
		*a = *b;
	}
	*b = tmp;
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	if (!(*b))
	{
		*b = *a;
		(*b)->next = NULL;
	}
	else
	{
		(*a)->next = *b;
		(*b)->prev = *a;
		*b = *a;
	}
	*a = tmp;
}
