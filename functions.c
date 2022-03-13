/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:12:53 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 16:13:20 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **a, int n)
{
	t_stack	*head;
	t_stack	*rotate;
	t_stack	*penultimate;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	head = (*a);
	penultimate = (*a);
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	rotate = penultimate->next;
	penultimate->next = NULL;
	rotate->next = head;
	*a = rotate;
	if (n == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int n)
{
	t_stack	*head;
	t_stack	*rotate;
	t_stack	*penultimate;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	head = (*b);
	penultimate = (*b);
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	rotate = penultimate->next;
	penultimate->next = NULL;
	rotate->next = head;
	*b = rotate;
	if (n == 1)
		write(1, "rrb\n", 4);
}

void	ft_sb(t_stack *b, int i)
{
	int		buff;

	if (b == NULL || b->next == NULL)
		return ;
	buff = b->val;
	b->val = b->next->val;
	b->next->val = buff;
	if (i == 1)
		write(1, "sb\n", 3);
}
