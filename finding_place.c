/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:09:35 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 16:11:00 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller_element(t_stack *a, int a_val, int b_val)
{
	t_stack	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->val < a_val && save->val > b_val)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

void	sub_finding_place(t_stacks *stacks, t_stack *b, int *action, int *tmp)
{
	while (stacks->a)
	{
		*tmp = stacks->a->val;
		if (b->val > stacks->a->val)
		{
			*action += 1;
			if (b->val < stacks->a->next->val)
				break ;
			stacks->a = stacks->a->next;
		}
		else
			break ;
	}
	if (smaller_element(stacks->a, *tmp, b->val) == 1)
	{
		while (stacks->a)
		{
			if (stacks->a->val < *tmp && stacks->a->val > b->val)
				break ;
			*action += 1;
			stacks->a = stacks->a->next;
		}
	}
}

int	finding_place(t_stacks *stacks, t_stack *b, t_steps *steps, int min)
{
	int	action;
	int	res;
	int	tmp;

	action = 0;
	tmp = 0;
	sub_finding_place(stacks, b, &action, &tmp);
	if (stacks->a->rotate == -1)
		action = stacks->count_a - action;
	if (min == -1 || (action + b->steps) < min)
	{
		steps->dest_a = stacks->a->rotate;
		steps->dest_b = b->rotate;
		steps->count_a = action;
		steps->count_b = b->steps;
		res = action + b->steps;
	}
	else
		res = min;
	return (res);
}

int	count_to_min(t_stack *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->val == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
