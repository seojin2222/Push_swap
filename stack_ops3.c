#include "push_swap.h"

void    rrr(t_ps *ps)
{
    int tmp;
    int i;

    if (ps->a.size >= 2)
    {
        tmp = ps->a.data[ps->a.size - 1];
        i = ps->a.size - 1;
        while (i > 0)
        {
            ps->a.data[i] = ps->a.data[i - 1];
            i--;
        }
        ps->a.data[0] = tmp;
    }
    if (ps->b.size >= 2)
    {
        tmp = ps->b.data[ps->b.size - 1];
        i = ps->b.size - 1;
        while (i > 0)
        {
            ps->b.data[i] = ps->b.data[i - 1];
            i--;
        }
        ps->b.data[0] = tmp;
    }
    write(1, "rrr\n", 4);
}