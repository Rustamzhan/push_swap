/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:51:36 by astanton          #+#    #+#             */
/*   Updated: 2019/10/03 14:51:38 by astanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_swap_header.h"

static int		ft_count_words(int ac, char **av)
{
	int	i;
	int	j;
	int	count_words;

	i = (!ft_strcmp("-v", av[1])) ? 1 : 0;
	count_words = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] != '\t' && av[i][j] != ' ') && (av[i][j + 1] == ' ' ||
				av[i][j + 1] == '\t' || av[i][j + 1] == '\0'))
				count_words++;
			j++;
		}
	}
	return (count_words);
}

static void		ft_free_tmp(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

static void		ft_check_and_fill_array(char *str, int *result, int *i)
{
	char	**tmp;
	int		j;

	tmp = ft_strsplit_spaces(str);
	j = 0;
	while (tmp[j])
	{
		if (!(ft_isnumber(tmp[j]) && ft_isint(tmp[j])))
		{
			ft_free_tmp(tmp);
			free(result);
			write(1, "Error\n", 6);
			exit(1);
		}
		else
			result[*i] = ft_atoi(tmp[j]);
		(*i)++;
		j++;
	}
	ft_free_tmp(tmp);
}

int				*prepare_array_of_numbers(int ac, char **av)
{
	int	count_words;
	int	*result;
	int	i;

	count_words = ft_count_words(ac, av);
	if (!(result = (int *)malloc((count_words + 1) * sizeof(int))))
		exit(1);
	result[0] = count_words;
	count_words = 1;
	i = (!ft_strcmp("-v", av[1])) ? 2 : 1;
	while (i < ac)
	{
		ft_check_and_fill_array(av[i], result, &count_words);
		i++;
	}
	if (!ft_check_duplicates(result))
	{
		free(result);
		write(1, "Error\n", 6);
		exit(1);
	}
	return (result);
}
