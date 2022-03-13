/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_and_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:12:58 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 17:13:26 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_stack *stack)
{
	int	max;

	max = stack->val;
	while (stack)
	{
		if (max < stack->val)
			max = stack->val;
		stack = stack->next;
	}
	return (max);
}

void	sort_3(t_stacks *stacks)
{
	int	max;

	max = ft_max(stacks->a);
	if (stacks->count_a == 1)
		return ;
	else if (stacks->count_a == 2)
	{
		if (stacks->a->val > stacks->a->next->val)
			ft_sa(stacks->a, 1);
		return ;
	}
	else if (stacks->count_a == 3)
	{
		if (stacks->a->val == max)
			ft_ra(&stacks->a, 1);
		if (stacks->a->next->val == max)
			ft_rra(&stacks->a, 1);
		if (stacks->a->val > stacks->a->next->val)
			ft_sa(stacks->a, 1);
	}
}

void	sort_5(t_stacks *stacks)
{
	while (stacks->count_b < 2)
	{
		if (stacks->a->val == stacks->min || stacks->a->val == stacks->max)
			ft_pb(stacks, 1);
		else
			ft_ra(&stacks->a, 1);
	}
	sort_3(stacks);
	ft_pa(stacks, 1);
	ft_pa(stacks, 1);
	if (stacks->a->val == stacks->min)
		ft_sa(stacks->a, 1);
	ft_ra(&stacks->a, 1);
}
