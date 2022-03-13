/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:41:21 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 17:07:34 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		sort_3(stacks);
	else if (stacks->count_a <= 5)
		sort_5(stacks);
	else
		big_sort(stacks);
}

void	start_push_swap(int argc, char **argv, t_data *new, t_stacks *stacks)
{
	if (check_validation(argc, argv))
	{
		separation(argc, argv, new);
		parse_and_dups(new, stacks);
		if (check_sorted(new))
		{
			init_stack(new, stacks);
			ft_sort(stacks);
			free_stack(stacks);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	if (argc < 2)
		exit(EXIT_FAILURE);
	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		exit(EXIT_FAILURE);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(EXIT_FAILURE);
	ft_null(stacks, new);
	start_push_swap(argc, argv, new, stacks);
	free(new);
	free(stacks);
	return (0);
}
