/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:13:36 by fcelesti          #+#    #+#             */
/*   Updated: 2022/03/12 17:21:03 by fcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countword(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			count++;
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

int	ft_wordmalloc(char const *s, char **mass)
{
	int	lenword;
	int	i;

	i = 0;
	while (*s)
	{
		lenword = 0;
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
			{
				s++;
				lenword++;
			}
			mass[i] = ((char *)malloc(sizeof(char) * (lenword + 1)));
			if (!mass[i++])
				return (i);
		}
		else
			s++;
	}
	return (0);
}

void	ft_rewriting(char const *s, char **mass)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				mass[i][j++] = *s++;
			mass[i++][j] = '\0';
		}
		j = 0;
		if (*s != '\0')
			s++;
	}
}

char	**ft_strsplit(char const *s, int count)
{
	char	**mass;
	int		res;

	if (!s)
		return (NULL);
	mass = (char **)malloc(sizeof(char *) * (count + 1));
	if (!mass)
		exit(1);
	mass[count] = NULL;
	res = ft_wordmalloc(s, mass);
	if (res == 0)
		ft_rewriting(s, mass);
	else
	{
		while (res != 0)
		{
			free(mass[res]);
			mass[res--] = NULL;
		}
		free(mass);
	}
	return ((char **)mass);
}
