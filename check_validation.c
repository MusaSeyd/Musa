/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:56:52 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 14:50:29 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	has_numbers(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	err_msg();
}

void	str_valid(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				err_msg();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-')
				&& (sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			err_msg();
		i++;
	}
}

int	check_validation(int argc, char **argv)
{
	int	res;
	int	i;

	res = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_spaces(argv[i]))
		{
			has_numbers(argv[i]);
			str_valid(argv[i]);
			res = 1;
		}
		i++;
	}
	return (res);
}

void	check_dups(const int *dup, int count)
{
	int	i;

	i = 0;
	while (i != count)
	{
		if (dup[i] == dup[i + 1])
			err_msg();
		i++;
	}
}

void	parse_and_dups(t_data *new, t_stacks *stacks)
{
	int	*dup;

	dup = (int *)malloc(sizeof(int) * new->count);
	if (!dup)
		exit(EXIT_FAILURE);
	dup = ft_intcpy(dup, new->a, new->count);
	quick_sort(dup, 0, new->count - 1);
	check_dups(dup, new->count - 1);
	stacks->count_a = new->count;
	stacks->count_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->count / 2];
	stacks->max = dup[new->count - 1];
	free(dup);
}
