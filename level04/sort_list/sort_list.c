# include <stdio.h>
# include <stdlib.h>
# include "ft_list.h"


int cmp(int a, int b)
{
    return a - b;
}
t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int access;
    void *tmp;
    t_list *begin;

    if(!lst || !cmp)
        return NULL;
    
    access = 1;
    while(access)
    {
        access = 0;
        begin = lst;
        while(begin->next)
        {
            if(cmp(*(int*)begin->data, *(int*)begin->next->data) > 0)
            {
                tmp = begin->data;
                begin->data = begin->next->data;
                begin->next->data = tmp;
                access = 1;
            }
            begin = begin->next;
        }
    }
    return lst;
}
void print_list(t_list *node)
{
    if(!node)
        return ;
    else
        printf("%d ", *(int *)node->data);
    print_list(node->next);
}
int main()
{
    t_list *head = NULL;

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    t_list *node4 = malloc(sizeof(t_list));

    if(!node1 || !node2 || !node3 || !node4)
        return 0;

    int a = 10;
    int b = 1;
    int c = 120;
    int d = 0;

    node1->data = &a;
    node1->next = node2;

    node2->data = &b;
    node2->next = node3;

    node3->data = &c;
    node3->next = node4;

    node4->data = &d;
    node4->next = NULL;

    head = node1;

    printf("before : ");
    print_list(head);
    printf("\n-------------\n");
    sort_list(head, cmp);
    printf("after  : ");
    print_list(head);
}