
void sort_int_tab(int *tab, unsigned int size)
{
    int i;
    int j;
    if(size == 0 || !tab)
        return;

    i = 0;
    while(i < size - 1)
    {
        j = i + 1;
        while(j < size)
        {
            if(tab[i] > tab[j])
            {
                int tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
}
// # include <stdio.h>
// int main()
// {
//     int tab[] = {12, 3, 1, 33, 4};
//     int size = 5;
//     int i = 0;
//     sort_int_tab(tab, size);
//     while(i < size)
//     {
//         printf("%d ", tab[i++]);
//     }
// }