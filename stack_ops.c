#include "push_swap.h"

void    sa(t_ps *ps)
{
    int tmp;

    if (ps->a.size < 2)
        return ;
    tmp = ps->a.data[0];
    ps->a.data[0] = ps->a.data[1];
    ps->a.data[1] = tmp;

    write(1, "sa\n", 3);  
}

void    sb(t_ps *ps)
{
    int tmp;

    if (ps->b.size < 2)
        return ;
    tmp = ps->b.data[0];
    ps->b.data[0] = ps->b.data[1];
    ps->b.data[1] = tmp;

    write(1, "sb\n", 3);
}

void    ss(t_ps *ps)
{
    if (ps->a.size >= 2)
	{
		int tmp = ps->a.data[0];
		ps->a.data[0] = ps->a.data[1];
		ps->a.data[1] = tmp;
	}
	if (ps->b.size >= 2)
	{
		int tmp = ps->b.data[0];
		ps->b.data[0] = ps->b.data[1];
		ps->b.data[1] = tmp;
	}
    write(1, "ss\n", 3);
}

void	pa(t_ps *ps)
{
	int	tmp;
	int	i;

	if (ps->b.size == 0)
		return ;
	tmp = ps->b.data[0];

	// B에서 제거
	i = 0;
	while (i + 1 < ps->b.size)
	{
		ps->b.data[i] = ps->b.data[i + 1];
		i++;
	}
	ps->b.size--;

	// A에 삽입
	i = ps->a.size;
	while (i > 0)
	{
		ps->a.data[i] = ps->a.data[i - 1];
		i--;
	}
	ps->a.data[0] = tmp;
	ps->a.size++;

	write(1, "pa\n", 3);
}


void	pb(t_ps *ps)
{
	int	tmp;
	int	i;

	if (ps->a.size == 0)
		return ;
	tmp = ps->a.data[0];

	i = 0;
	while (i + 1 < ps->a.size)
	{
		ps->a.data[i] = ps->a.data[i + 1];
		i++;
	}
	ps->a.size--;

	i = ps->b.size;
	while (i > 0)
	{
		ps->b.data[i] = ps->b.data[i - 1];
		i--;
	}
	ps->b.data[0] = tmp;
	ps->b.size++;

	write(1, "pb\n", 3);
}