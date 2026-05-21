# include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    int len;
    len = 0;
    while(begin_list)
    {
        begin_list = begin_list->next;
        len++;
    }
    return len;
}