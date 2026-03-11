/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojikim <seojikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 05:11:52 by seojikim          #+#    #+#             */
/*   Updated: 2026/01/20 05:18:12 by seojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_error(t_ps *ps)
{
	free_ps(ps);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	if (!init_ps(&ps, argc, argv))
		return (handle_error(&ps));
	if (is_sorted(&ps.a))
	{
		free_ps(&ps);
		return (0);
	}
	sort_stack(&ps);
	free_ps(&ps);
	return (0);
}
