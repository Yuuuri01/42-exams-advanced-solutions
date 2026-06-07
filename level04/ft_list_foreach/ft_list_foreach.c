# include <stdio.h>
# include <stdlib.h>
# include "ft_list.h"


void f(void *data)
{
    if(*(int *)data == 0)
        *(int *)data = 300;
}
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *trave;
    if(!begin_list || !f)
        return;
    trave = begin_list;
    while(trave)
    {
        f(trave->data);
        trave = trave->next;
    }
}
void print_list(t_list *node)
{
    if(!node)
        return;
    printf("%d\n", *(int *)node->data);
    print_list(node->next);
}
int main()
{
    t_list *head = NULL;

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    int s1 = 0;
    int s2 = 0;
    int s3 = 0;

    head = node1;

    node1->data = &s1;
    node1->next = node2;

    node2->data = &s2;
    node2->next = node3;

    node3->data = &s3;
    node3->next = NULL;

    printf("before : \n");
    print_list(head);
    printf("---------------------------\n");
    ft_list_foreach(head, f);
    printf("\nafter : \n");
    print_list(head);
}

