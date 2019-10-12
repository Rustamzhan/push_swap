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

void	push_a(t_container *a, t_container *b)
{
	t_stack	*tmp;

	if (b->stack == NULL)
		return ;
	tmp = b->stack->next;
	if (!(a->stack))
	{
		a->stack = b->stack;
		(a->stack->next) ? a->stack->next->prev = NULL : 0;
		a->stack->next = NULL;
		a->stack->prev = NULL;
		a->height = 1;
	}
	else
	{
		(b->stack->next) ? b->stack->next->prev = NULL : 0;
		b->stack->next = a->stack;
		a->stack->prev = b->stack;
		a->stack = b->stack;
		a->height++;
	}
	b->stack = tmp;
	b->height--;
}

void	push_b(t_container *a, t_container *b)
{
	t_stack	*tmp;

	if (a->stack == NULL)
		return ;
	tmp = a->stack->next;
	if (!(b->stack))
	{
		b->stack = a->stack;
		(b->stack->next) ? b->stack->next->prev = NULL : 0;
		b->stack->next = NULL;
		b->stack->prev = NULL;
		b->height = 1;
	}
	else
	{
		(a->stack->next) ? a->stack->next->prev = NULL : 0;
		a->stack->next = b->stack;
		b->stack->prev = a->stack;
		b->stack = a->stack;
		b->height++;
	}
	a->stack = tmp;
	a->height--;
}
