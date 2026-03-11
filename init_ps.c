/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojikim <seojikim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:27:40 by seojikim          #+#    #+#             */
/*   Updated: 2026/03/10 17:27:42 by seojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_empty_ps(t_ps *ps)
{
	ps->a.data = 0;
	ps->a.size = 0;
	ps->a.cap = 0;
	ps->b.data = 0;
	ps->b.size = 0;
	ps->b.cap = 0;
	ps->n = 0;
}

static int	alloc_stacks(t_ps *ps, int total)
{
	ps->n = total;
	ps->a.data = (int *)malloc(sizeof(int) * ps->n);
	ps->b.data = (int *)malloc(sizeof(int) * ps->n);
	if (!ps->a.data || !ps->b.data)
		return (0);
	ps->a.size = ps->n;
	ps->a.cap = ps->n;
	ps->b.size = 0;
	ps->b.cap = ps->n;
	return (1);
}

static int	fill_from_split(t_ps *ps, char **split, int *idx)
{
	int		j;
	int		ok;
	long	value;

	j = 0;
	while (split[j])
	{
		value = ft_atoi(split[j], &ok);
		if (!ok || value < INT_MIN || value > INT_MAX)
			return (0);
		ps->a.data[*idx] = (int)value;
		(*idx)++;
		j++;
	}
	return (1);
}

static int	fill_stack_a(t_ps *ps, int argc, char **argv)
{
	char	**split;
	int		i;
	int		idx;

	i = 1;
	idx = 0;
	while (i < argc)
	{
		split = ft_split(argv[i]);
		if (!split)
			return (0);
		if (!fill_from_split(ps, split, &idx))
			return (free_split(split), 0);
		free_split(split);
		i++;
	}
	return (!has_duplicate(&ps->a));
}

int	init_ps(t_ps *ps, int argc, char **argv)
{
	int	total;

	init_empty_ps(ps);
	total = count_total_numbers(argc, argv);
	if (total <= 0)
		return (0);
	if (!alloc_stacks(ps, total))
		return (0);
	if (!fill_stack_a(ps, argc, argv))
		return (0);
	return (1);
}
