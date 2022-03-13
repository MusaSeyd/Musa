/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:11:35 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 16:11:36 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, int n)
{
	int	tmp;

	if (a == NULL || a->next == NULL)
		return ;
	tmp = a->val;
	a->val = a->next->val;
	a->next->val = tmp;
	if (n == 1)
		write(1, "sa\n", 3);
}

void	ft_ra(t_stack **a, int n)
{
	t_stack	*head;
	t_stack	*rotate;
	t_stack	*last;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	rotate = *a;
	head = (*a)->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	rotate->next = NULL;
	last->next = rotate;
	*a = head;
	if (n == 1)
		write(1, "ra\n", 3);
}

void	ft_pb(t_stacks	*stacks, int n)
{
	t_stack	*tmp;

	if (stacks->a == NULL)
		return ;
	stacks->count_a -= 1;
	stacks->count_b += 1;
	tmp = stacks->a;
	stacks->a = stacks->a->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
	if (n == 1)
		write(1, "pb\n", 3);
}

void	ft_pa(t_stacks *stacks, int n)
{
	t_stack	*tmp;

	if (stacks->b == NULL)
		return ;
	stacks->count_a += 1;
	stacks->count_b -= 1;
	tmp = stacks->b;
	stacks->b = stacks->b->next;
	tmp->next = stacks->a;
	stacks->a = tmp;
	if (n == 1)
		write(1, "pa\n", 3);
}

void	ft_rb(t_stack **b, int n)
{
	t_stack	*head;
	t_stack	*rotate;
	t_stack	*last;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	rotate = *b;
	head = (*b)->next;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	rotate->next = NULL;
	last->next = rotate;
	*b = head;
	if (n == 1)
		write(1, "rb\n", 3);
}
