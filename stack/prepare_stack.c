/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:40:46 by astanton          #+#    #+#             */
/*   Updated: 2019/10/03 10:40:49 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static void	create_stack(t_stack *stack, int *numbers)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	while (++i < numbers[0] + 1)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			exit(1);
		tmp->num = numbers[i];
		tmp->next = NULL;
		tmp->prev = stack;
		stack->next = tmp;
		stack = stack->next;
	}
}

int			prepare_stack(t_container *a, int ac, char **av)
{
	int		*numbers;
	t_stack	*head;

	numbers = prepare_array_of_numbers(a, ac, av);
	a->height = numbers[0];
	if (numbers[0] == 0)
	{
		free(numbers);
		return (0);
	}
	a->height = numbers[0];
	if (!(head = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	head->num = numbers[1];
	head->next = NULL;
	head->prev = NULL;
	a->stack = head;
	create_stack(head, numbers);
	free(numbers);
	return (1);
}
