#include <unistd.h>

void    ra(t_ps *ps)
{
    int tmp;
    int i;

    if (ps->a.size < 2)
        return ;
    tmp = ps->a.data[0];
    i = 0;
    while (i + 1 < ps->a.size)
    {
        ps->a.data[i] = ps->a.data[i+1];
        i++;
    }
    ps->a.data[i] = tmp;
    write(1, "ra\n", 3);
}

void    rb(t_ps *ps)
{
    int tmp;
    int i;

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
void    rr(t_ps *ps)
{
    int tmp;
    int i;

    if (ps->a.size >= 2)
    {
        tmp = ps->a.data[0];
        i = 0;
        while (i + 1 < ps->a.size)
        {
            ps->a.data[i] = ps->a.data[i + 1];
            i++;
        }
        ps->a.data[i] = tmp;
    }
    if (ps->b.size >= 2)
    {
        tmp = ps->b.data[0];
        i = 0;
        while (i + 1 < ps->b.size)
        {
            ps->b.data[i] = ps->b.data[i + 1];
            i++;
        }
        ps->b.data[i] = tmp;
    }
    write(1, "rr\n", 3);
}

//됐나요?