/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:11:42 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 17:11:43 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	temp;
	int	j;

	pivot = arr[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = temp;
	return (i + 1);
}

void	quick_sort(int *arr, int start, int end)
{
	int	a;

	if (start < end)
	{
		a = partition(arr, start, end);
		quick_sort(arr, start, a - 1);
		quick_sort(arr, a + 1, end);
	}
}
