/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojikim <seojikim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:28:31 by seojikim          #+#    #+#             */
/*   Updated: 2026/03/10 17:28:35 by seojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	return (56);
}

void	push_chunks_to_b(t_ps *ps)
{
	int	chunk_size;
	int	chunk_end;

	chunk_size = get_chunk_size(ps->n);
	chunk_end = chunk_size;
	while (ps->a.size > 0)
	{
		if (ps->a.data[0] < chunk_end)
		{
			pb(ps);
			if (ps->b.data[0] < chunk_end - (chunk_size / 2))
				rb(ps);
			if (ps->b.size == chunk_end && chunk_end < ps->n)
				chunk_end += chunk_size;
		}
		else
			ra(ps);
	}
}

static int	find_max_pos(t_stack *b)
{
	int	i;
	int	max_idx;

	i = 1;
	max_idx = 0;
	while (i < b->size)
	{
		if (b->data[i] > b->data[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

void	push_back_to_a(t_ps *ps)
{
	int	max_pos;
	int	rot;

	while (ps->b.size > 0)
	{
		max_pos = find_max_pos(&ps->b);
		if (max_pos <= ps->b.size / 2)
		{
			while (max_pos > 0)
			{
				rb(ps);
				max_pos--;
			}
		}
		else
		{
			rot = ps->b.size - max_pos;
			while (rot > 0)
			{
				rrb(ps);
				rot--;
			}
		}
		pa(ps);
	}
}
