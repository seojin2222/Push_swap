/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojikim <seojikim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:29:28 by seojikim          #+#    #+#             */
/*   Updated: 2026/03/10 18:29:30 by seojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_sign(const char *str, int *i, int *sign)
{
	*sign = 1;
	if (!str[*i])
		return (0);
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (!str[*i])
		return (0);
	return (1);
}

long	ft_atoi(const char *str, int *ok)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	i = 0;
	*ok = 0;
	if (!parse_sign(str, &i, &sign))
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	*ok = 1;
	return (num * sign);
}

int	has_duplicate(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->data[i] == a->data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_ps(t_ps *ps)
{
	if (ps->a.data)
		free(ps->a.data);
	if (ps->b.data)
		free(ps->b.data);
	ps->a.data = 0;
	ps->b.data = 0;
	ps->a.size = 0;
	ps->b.size = 0;
	ps->a.cap = 0;
	ps->b.cap = 0;
	ps->n = 0;
}
