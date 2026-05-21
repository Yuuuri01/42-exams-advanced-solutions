# include <stdio.h>
# include <stdlib.h>


int     *ft_range(int start, int end)
{
    int i;
    int len;
    int *tab;

    if(end > start)
        len = end - start + 1;
    else
        len = start - end + 1;
    
    tab = malloc(len * sizeof(int));
    if(!tab)
        return NULL;


    i = 0;
    while(i < len)
    {
        tab[i++] = start;
        if(start > end)
            start--;
        else
            start++;
    }
    return tab;
}
int main()
{
    int start = 0;
    int end = -3;
    int i = 0;
    int len = start - end +  1;
    int *tab = ft_range(start, end);
    while(i < len)
    {
        printf("%d ", tab[i++]);
    }
    printf("\n");
    free(tab);
}