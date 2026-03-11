/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojikim <seojikim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:28:25 by seojikim          #+#    #+#             */
/*   Updated: 2026/03/10 17:28:27 by seojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	int	tmp;
	int	i;

	if (ps->a.size < 2)
		return ;
	tmp = ps->a.data[0];
	i = 0;
	while (i + 1 < ps->a.size)
	{
		ps->a.data[i] = ps->a.data[i + 1];
		i++;
	}
	ps->a.data[i] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_ps *ps)
{
	int	tmp;
	int	i;

	if (ps->b.size < 2)
		return ;
	tmp = ps->b.data[0];
	i = 0;
	while (i + 1 < ps->b.size)
	{
		ps->b.data[i] = ps->b.data[i + 1];
		i++;
	}
	ps->b.data[i] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_ps *ps)
{
	int	tmp;
	int	i;
	int	ok;

	ok = 0;
	if (ps->a.size >= 2)
	{
		tmp = ps->a.data[0];
		i = -1;
		while (++i + 1 < ps->a.size)
			ps->a.data[i] = ps->a.data[i + 1];
		ps->a.data[i] = tmp;
		ok = 1;
	}
	if (ps->b.size >= 2)
	{
		tmp = ps->b.data[0];
		i = -1;
		while (++i + 1 < ps->b.size)
			ps->b.data[i] = ps->b.data[i + 1];
		ps->b.data[i] = tmp;
		ok = 1;
	}
	if (ok)
		write(1, "rr\n", 3);
}

void	rra(t_ps *ps)
{
	int	tmp;
	int	i;

	if (ps->a.size < 2)
		return ;
	tmp = ps->a.data[ps->a.size - 1];
	i = ps->a.size - 1;
	while (i > 0)
	{
		ps->a.data[i] = ps->a.data[i - 1];
		i--;
	}
	ps->a.data[0] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_ps *ps)
{
	int	tmp;
	int	i;

	if (ps->b.size < 2)
		return ;
	tmp = ps->b.data[ps->b.size - 1];
	i = ps->b.size - 1;
	while (i > 0)
	{
		ps->b.data[i] = ps->b.data[i - 1];
		i--;
	}
	ps->b.data[0] = tmp;
	write(1, "rrb\n", 4);
}
