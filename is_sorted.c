#include "push_swap.h"

int is_sorted(t_stack *a)
{
    int i;

    i = 0;
    while (i + 1 < a->size)
    {
        if (a->data[i] > a->data[i + 1])
            return (0);
        i++;
    }
    return (1);
}