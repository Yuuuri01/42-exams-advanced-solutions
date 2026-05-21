# include <unistd.h>



int main(int ac, char **av)
{
    if(ac == 3)
    {
        int tab[256] = {0};
        int i = 0;  

        while(av[1][i])
        {
            tab[av[1][i]] = 1;
            i++;
        }

        i = 0;
        while(av[2][i])
        {
            tab[av[2][i]] = 1;
            i++;
        }
        while(*av[1])
        {
            if(tab[*av[1]] == 1)
            {
                write(1, &(*av[1]), 1);
                tab[*av[1]] = 0;
            }
            av[1]++;
        }
        while(*av[2])
        {
            if(tab[*av[2]] == 1)
            {
                write(1, &(*av[2]), 1);
                tab[*av[2]] = 0;
            }
            av[2]++;
        }
    }
    write(1, "\n", 1);
}