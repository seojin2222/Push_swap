/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_total_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojikim <seojikim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:09:24 by seojikim          #+#    #+#             */
/*   Updated: 2026/03/10 20:09:26 by seojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_total_numbers(int argc, char **argv)
{
	char	**split;
	int		i;
	int		j;
	int		total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		split = ft_split(argv[i]);
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			total++;
			j++;
		}
		free_split(split);
		i++;
	}
	return (total);
}
