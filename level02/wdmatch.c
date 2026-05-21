# include <unistd.h>

int main(int ac, char **av)
{
    if(ac == 3)
    {
        int j = 0;
        while(*av[2])
        {
            if(av[1][j] == *av[2])
                j++;
            av[2]++;
        }
        if(!av[1][j])
            write(1, av[1], j);
    }
    write(1, "\n", 1);
}