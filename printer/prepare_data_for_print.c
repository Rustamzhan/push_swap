/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_data_for_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 04:27:29 by astanton          #+#    #+#             */
/*   Updated: 2019/10/12 04:27:32 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static int	find_stack_len(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

static void	sort_array(int *nums, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i;
		while (++j < len)
		{
			if (nums[j] < nums[i])
			{
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
		i++;
	}
}

void		prepare_ranks(t_container *a)
{
	int		*nums;
	int		len;
	int		i;
	t_stack	*tmp;

	a->amount_of_nums = a->height;
	tmp = a->stack;
	len = find_stack_len(tmp);
	nums = (int*)malloc(sizeof(int) * len);
	len = 0;
	while (tmp)
	{
		nums[len] = tmp->num;
		tmp = tmp->next;
		len++;
	}
	sort_array(nums, len);
	tmp = a->stack;
	while (tmp)
	{
		i = -1;
		while (++i < len)
			tmp->rank = (nums[i] == tmp->num) ? i + 1 : tmp->rank;
		tmp = tmp->next;
	}
}

int			fill_flags(t_container *a, t_container *b, char *arg)
{
	b->stack = NULL;
	b->height = 0;
	if (!ft_strcmp("-v", arg) || !ft_strcmp("-vp", arg))
	{
		a->print = 1;
		a->step = (arg[2] == 'p') ? 1 : 0;
		return (1);
	}
	a->print = 0;
	a->step = 0;
	return (0);
}
