/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:44:31 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 13:47:13 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	steps_markup(t_stack *stack, int count)
{
	int		i;
	int		iter;
	t_stack	*tmp;

	i = -1;
	iter = count / 2;
	tmp = stack;
	while (iter >= ++i)
	{
		tmp->steps = i;
		tmp->rotate = 1;
		tmp = tmp->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		tmp->steps = i;
		tmp->rotate = -1;
		tmp = tmp->next;
	}
}

void	min_steps(t_stacks *stacks, t_steps *steps)
{
	int		min_steps;
	t_stack	*head_a;
	t_stack	*head_b;

	min_steps = -1;
	head_a = stacks->a;
	head_b = stacks->b;
	while (stacks->b)
	{
		min_steps = finding_place(stacks, stacks->b, steps, min_steps);
		stacks->a = head_a;
		stacks->b = stacks->b->next;
	}
	stacks->b = head_b;
}

void	instruction_execution(t_stacks *stacks, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			ft_ra(&stacks->a, 1);
		else
			ft_rra(&stacks->a, 1);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			ft_rb(&stacks->b, 1);
		else
			ft_rrb(&stacks->b, 1);
		steps->count_b--;
	}
	ft_pa(stacks, 1);
}

void	begin_sort(t_stacks *stacks)
{
	t_steps	*steps;

	steps = (t_steps *)malloc(sizeof(t_steps));
	if (!steps)
		exit(EXIT_FAILURE);
	while (stacks->count_b != 0)
	{
		steps->count_a = -1;
		steps->count_b = -1;
		steps->dest_a = 0;
		steps->dest_b = 0;
		steps_markup(stacks->a, stacks->count_a);
		steps_markup(stacks->b, stacks->count_b);
		min_steps(stacks, steps);
		instruction_execution(stacks, steps);
	}
	if ((count_to_min(stacks->a, stacks->min)) > stacks->count_a / 2)
	{
		while (stacks->a->val != stacks->min)
			ft_rra(&stacks->a, 1);
	}
	else
		while (stacks->a->val != stacks->min)
			ft_ra(&stacks->a, 1);
	free(steps);
}

void	big_sort(t_stacks *stacks)
{
	while (stacks->count_a > 2)
	{
		if (stacks->a->val != stacks->min && stacks->a->val != stacks->max)
		{
			ft_pb(stacks, 1);
			if (stacks->b->val > stacks->med)
				ft_rb(&stacks->b, 1);
		}
		else
			ft_ra(&stacks->a, 1);
	}
	if (stacks->a->val < stacks->a->next->val)
		ft_sa(stacks->a, 1);
	ft_pa(stacks, 1);
	begin_sort(stacks);
}
