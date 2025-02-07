/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:32:08 by astanton          #+#    #+#             */
/*   Updated: 2019/10/01 15:32:10 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

int			ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if ((i > 0 && (str[i] == '-' || str[i] == '+')) ||
			(!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+') ||
			((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int			ft_isint(char *str)
{
	int	len;
	int	i;

	i = 0;
	while ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '+' ||
			str[i + 1] == '-'))
		i++;
	len = ft_strlen(&str[i]);
	if ((len > 10 && (str[i] != '-' && str[i] != '+')) || len > 11)
		return (0);
	else if (len == 11 && str[i] == '-' && ft_strcmp("2147483648",
			&str[i + 1]) < 0)
		return (0);
	else if (len == 11 && str[i] == '+' && ft_strcmp("2147483647",
			&str[i + 1]) < 0)
		return (0);
	else if (len == 10 && ft_strcmp("2147483647", str) < 0)
		return (0);
	return (1);
}

int			ft_check_duplicates(int *result)
{
	int	i;
	int	j;

	i = 0;
	while (++i < result[0] + 1)
	{
		j = i;
		while (++j < result[0] + 1)
		{
			if (result[i] == result[j])
				return (0);
		}
	}
	return (1);
}

static void	free_stack(t_container *stack)
{
	t_stack	*tmp;

	while (stack->height--)
	{
		tmp = stack->stack->next;
		free(stack->stack);
		stack->stack = NULL;
		stack->stack = tmp;
	}
}

void		ft_free_stacks(t_container *a, t_container *b)
{
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}
