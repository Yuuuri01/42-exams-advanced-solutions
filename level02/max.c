# include <stdio.h>


int		max(int* tab, unsigned int len)
{
    int max;
    if(!tab)
        return 0;

    max = tab[0];
    while(len > 0)
    {
        if(tab[len - 1] > max)
            max = tab[len - 1];
        len--;
    }
    return (max);
}
int main()
{
    int tab[] = {1, 2, 3, 100, 5, 700, 90};
    printf("%d\n", max(tab, 7));
}