/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojikim <seojikim@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 05:13:14 by seojikim          #+#    #+#             */
/*   Updated: 2026/02/02 17:19:49 by seojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*data;
	int	size;
	int	cap;
}	t_stack;

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
	int		n;
}	t_ps;

/* stack operations */
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);

/* init / free */
int		init_ps(t_ps *ps, int argc, char **argv);
void	free_ps(t_ps *ps);

/* parsing */
char	**ft_split(const char *s);
long	ft_atoi(const char *str, int *ok);
int		has_duplicate(t_stack *a);
int		count_total_numbers(int argc, char **argv);
void	free_split(char **arr);

/* sorting */
int		is_sorted(t_stack *a);
void	sort_stack(t_ps *ps);
void	sort_three(t_ps *ps);
void	sort_five(t_ps *ps);
void	sort_chunk(t_ps *ps);
void	compress_values(t_ps *ps);
void	push_chunks_to_b(t_ps *ps);
void	push_back_to_a(t_ps *ps);

#endif