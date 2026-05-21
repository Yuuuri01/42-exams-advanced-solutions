# include <stdlib.h>
# include <stdio.h>


int *ft_rrange(int start, int end)
{
    int *tab;
    int len;
    int i;

    if(end < start)
        len = start - end + 1;
    else
        len = end - start + 1;
    
    if(!(tab = malloc(len * sizeof(int))))
        return NULL;

    i = 0;
    while(i < len)
    {
        tab[i++] = end;
        if(end > start)
            end--;
        else
            end++;
    }
    return tab;
}
int main()
{
    int start = 0;
    int end = -3;
    int len;
    int *tab = ft_rrange(start, end);
    if(start > end)
        len = (start - end) + 1;
    else
        len = end - start + 1;
    int i = 0;
    while(i < len)
    {
        printf("%d ", tab[i++]);
    }
    printf("\n");
}