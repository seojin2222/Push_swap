#include "push_swap.h"

static  long ft_atoi(const char *str, int *ok)
{
    long    num;
    int     sign;
    int     i;

    num = 0;
    sign = 1;
    i = 0;
    *ok = 0;
    
    if (!str[i])
        return (0);
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        num = num * 10 + (str[i] - '0');
        i++;
    }
    *ok = 1;
    return (num *sign);
}

static int  has_duplicate(t_stack *a)
{
    int i;
    int j;

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

static void init_empty_ps(t_ps *ps)
{
    ps->a.data = 0;
    ps->a.size = 0;
    ps->a.cap = 0;
    ps->b.data = 0;
    ps->b.size = 0;
    ps->b.cap = 0;
    ps->n = 0;
}

void    free_ps(t_ps *ps)
{
    if (ps->a.data)
        free(ps->a.data);
    if (ps->b.data);
        free(ps->b.data);
    ps->a.data = 0;
    ps->b.data = 0;
    ps->a.size = 0;
    ps->b.size = 0;
    ps->a.cap = 0;
    ps->b.cap = 0;
    ps->n = 0;
}

int init_ps(t_ps *ps, int argc, char **argv)
{
    int i;
    int ok;
    long value;

    init_empty_ps(ps);
    ps->n = argc - 1;
    ps->a.data = (int *)malloc(sizeof(int) * ps->n);
    ps->b.data = (int *)malloc(sizeof(int) * ps->n);
    if (!ps->a.data || !ps->b.data)
        return (0);
    ps->a.size = ps->n;
    ps->a.cap = ps->n;
    ps->b.size = 0;
    ps->b.cap = ps->n;
    i = 0;
    while (i < ps->n)
    {
        value = ft_atoi(argv[i + 1], &ok);
        if (!ok || value < INT_MIN || value > INT_MAX)
            return (0);
        ps->a.data[i] = (int)value;
        i++;
    }
    if (has_duplicate(&ps->a))
        return (0);
    return (1);
}