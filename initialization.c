/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:53:42 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 16:21:30 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_null(t_stacks *stacks, t_data *new)
{
	stacks->a = NULL;
	stacks->a = NULL;
	stacks->count_a = 0;
	stacks->count_b = 0;
	stacks->max = 0;
	stacks->med = 0;
	stacks->min = 0;
	new->count = 0;
}

t_stack	*create_stack(const int *buff, int count)
{
	int		i;
	t_stack	*new_list;
	t_stack	*head;

	i = 0;
	new_list = (t_stack *)malloc(sizeof(t_stack));
	if (!new_list)
		exit(EXIT_FAILURE);
	head = new_list;
	while (i < count)
	{
		if (i < count - 1)
		{
			new_list->next = (t_stack *)malloc(sizeof(t_stack));
			if (!new_list->next)
				exit(EXIT_FAILURE);
		}
		new_list->val = buff[i];
		if (i == count - 1)
			new_list->next = NULL;
		else
			new_list = new_list->next;
		i++;
	}
	return (head);
}

void	init_stack(t_data *new, t_stacks *stacks)
{
	stacks->a = create_stack(new->a, new->count);
	stacks->b = NULL;
}

void	free_stack(t_stacks *stacks)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (i < stacks->count_a)
	{
		tmp = stacks->a;
		stacks->a = stacks->a->next;
		free(tmp);
		i++;
	}
	i = 0;
	while (i < stacks->count_b)
	{
		tmp = stacks->b;
		stacks->b = stacks->b->next;
		free(tmp);
		i++;
	}
}
