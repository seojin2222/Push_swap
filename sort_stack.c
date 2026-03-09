#include "push_swap.h"

void    sort_stack(t_ps *ps)
{
    if (ps->a.size == 2)
    {
        if (ps->a.data[0] > ps->a.data[1])
            sa(ps);
    }
    else if (ps->a.size == 3)
        sort_three(ps);
    else if (ps->a.size <= 5)
        sort_five(ps);
    else   
        sort_chunk(ps);
}

void    sort_three(t_ps *ps)
{
    int a;
    int b;
    int c;

    a = ps->a.data[0];
    b = ps->a.data[1];
    c = ps->a.data[2];
    if (a > b && b < c && a < c)
        sa(ps);
    else if (a > b && b > c)
    {
        sa(ps);
        rra(ps);
    }
    else if (a > b && b < c && a > c)
        ra(ps);
    else if (a < b && b > c && a < c)
    {
        sa(ps);
        ra(ps);
    }
    else if (a < b && b > c && a > c)
        rra(ps);
}
static int	find_min_pos(t_stack *a)
{
	int	i;
	int	min_idx;

	i = 1;
	min_idx = 0;
	while (i < a->size)
	{
		if (a->data[i] < a->data[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}
static void	move_min_to_top_a(t_ps *ps)
{
	int	min_pos;

	min_pos = find_min_pos(&ps->a);
	if (min_pos <= ps->a.size / 2)
	{
		while (min_pos > 0)
		{
			ra(ps);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < ps->a.size)
		{
			rra(ps);
			min_pos++;
		}
	}
}
void	sort_five(t_ps *ps)
{
	while (ps->a.size > 3)
	{
		move_min_to_top_a(ps);
		pb(ps);
	}
	sort_three(ps);
	while (ps->b.size > 0)
		pa(ps);
}