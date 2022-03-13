/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:40:44 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 17:11:05 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
	int		a[10000];
	int		count;
}	t_data;

typedef struct s_stack
{
	int				val;
	int				rotate;
	int				steps;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		count_a;
	int		count_b;
	int		min;
	int		max;
	int		med;
}	t_stacks;

typedef struct s_steps
{
	int	count_a;
	int	count_b;
	int	dest_a;
	int	dest_b;
}	t_steps;

void	err_msg(void);
void	ft_null(t_stacks *stacks, t_data *new);
int		ft_spaces(const char *str);
int		check_validation(int argc, char **argv);
int		ft_countword(char const *s);
char	**ft_strsplit(char const *s, int count);
void	separation(int argc, char **argv, t_data *new);
void	parse_and_dups(t_data *new, t_stacks *stacks);
int		*ft_intcpy(int *dst, const int *src, int count);
void	quick_sort(int *arr, int start, int end);
int		check_sorted(t_data *new);
void	init_stack(t_data *new, t_stacks *stacks);
void	sort_3(t_stacks *stacks);
void	sort_5(t_stacks *stacks);
void	ft_sa(t_stack *a, int n);
void	ft_ra(t_stack **a, int n);
void	ft_rra(t_stack **a, int n);
void	ft_rrb(t_stack **b, int n);
void	ft_pb(t_stacks	*stacks, int n);
void	ft_pa(t_stacks *stacks, int n);
void	ft_rb(t_stack **b, int n);
void	ft_sb(t_stack *b, int i);
int		finding_place(t_stacks *stacks, t_stack *stack, \
		t_steps *steps, int min);
void	big_sort(t_stacks *stacks);
int		count_to_min(t_stack *a, int min);
void	free_stack(t_stacks *stacks);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *before, char *buf);
size_t	ft_strlen(char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	ft_strdel(char **as);

#endif