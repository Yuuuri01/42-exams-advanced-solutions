# include "ft_list.h"
# include <stdlib.h>
// int cmp(void *a, void *b)
// {
//     if(*(int *) a == *(int *)b)
//         return 0;
//     return 1;
// }
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *prev;
    t_list *next;
    t_list *curr;
    t_list *tmp;

    if(!begin_list || !*begin_list || !data_ref || !cmp)
        return;

    prev = NULL;
    curr = *begin_list;
    while(curr)
    {
        next = curr->next;
        if(cmp(curr->data, data_ref) == 0)
        {
            tmp = curr;
            if(!prev)
                *begin_list = next;
            else
                prev->next = curr->next;
            free(tmp);
        }
        else
            prev = curr;
        curr = next;
    }
}