/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:50:50 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 17:30:36 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_action(char *cmd, t_stacks *stacks)
{
	if (ft_strncmp(cmd, "sa", 2) == 0)
		ft_sa(stacks->a, 0);
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		ft_ra(&stacks->a, 0);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		ft_rb(&stacks->b, 0);
	else if (ft_strncmp(cmd, "pa", 2) == 0)
		ft_pa(stacks, 0);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		ft_pb(stacks, 0);
	else if (ft_strncmp(cmd, "rra", 3) == 0)
		ft_rra(&stacks->a, 0);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		ft_rrb(&stacks->b, 0);
	else
		err_msg();
}

int	ft_stack_sorted(t_stacks *s)
{
	int		i;
	int		buff;
	t_stack	*save;

	i = 0;
	save = s->a;
	while (i < (s->count_a - 1))
	{
		buff = s->a->val;
		s->a = s->a->next;
		if (buff > s->a->val)
		{
			s->a = save;
			return (0);
		}
		i++;
	}
	s->a = save;
	return (1);
}

void	checker_execute(t_data *new, t_stacks *stacks, char *cmd)
{
	parse_and_dups(new, stacks);
	init_stack(new, stacks);
	cmd = get_next_line(0);
	while (cmd != NULL)
	{
		execute_action(cmd, stacks);
		free(cmd);
		cmd = get_next_line(0);
	}
	if ((ft_stack_sorted(stacks)) && stacks->count_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;
	char		*cmd;

	if (argc < 2)
		exit(EXIT_FAILURE);
	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		exit(EXIT_FAILURE);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(EXIT_FAILURE);
	ft_null(stacks, new);
	cmd = NULL;
	if (check_validation(argc, argv))
	{
		separation(argc, argv, new);
		checker_execute(new, stacks, cmd);
	}
	free_stack(stacks);
	free(new);
	free(stacks);
	return (0);
}
