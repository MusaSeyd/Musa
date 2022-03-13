/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:11:51 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 17:12:42 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_to_stack(t_data *new, int *buff, int count)
{
	int	i;

	i = -1;
	while (count > ++i)
		new->a[i + new->count] = buff[i];
	new->count += count;
	free(buff);
}

void	separation(int argc, char **argv, t_data *new)
{
	int		i;
	int		p;
	int		*buff;
	char	**arr;
	int		count;

	i = 1;
	while (i < argc)
	{
		p = -1;
		count = ft_countword(argv[i]);
		arr = ft_strsplit(argv[i], count);
		buff = (int *)malloc(sizeof(int) * count);
		if (!buff)
			exit(EXIT_FAILURE);
		while (count > ++p)
		{
			buff[p] = ft_atoi(arr[p]);
			free(arr[p]);
		}
		free(arr);
		arr_to_stack(new, buff, count);
		i++;
	}
}
