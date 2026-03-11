/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojikim <seojikim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:27:58 by seojikim          #+#    #+#             */
/*   Updated: 2026/03/10 17:27:59 by seojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	compress_values(t_ps *ps)
{
	int	*sorted;
	int	i;

	sorted = (int *)malloc(sizeof(int) * ps->a.size);
	if (!sorted)
		return ;
	i = 0;
	while (i < ps->a.size)
	{
		sorted[i] = ps->a.data[i];
		i++;
	}
	sort_int_array(sorted, ps->a.size);
	i = 0;
	while (i < ps->a.size)
	{
		ps->a.data[i] = find_index(sorted, ps->a.size, ps->a.data[i]);
		i++;
	}
	free(sorted);
}

void	sort_chunk(t_ps *ps)
{
	compress_values(ps);
	push_chunks_to_b(ps);
	push_back_to_a(ps);
}
