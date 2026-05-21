# include <unistd.h>


int main(int ac, char **av)
{
    if(ac == 2)
    {
        while(*av[1] && (*av[1] == 32 || *av[1] == 9))
            av[1]++;
        while(*av[1])
        {
            if(*av[1] == 32 || *av[1] == 9)
            {
                if(*(av[1] + 1) && (*(av[1] + 1) != 32) && (*(av[1] + 1) != 9))
                    write(1, "   ", 3);
            }
            else
                write(1, &(*av[1]), 1);
            av[1]++;
        }
    }
    write(1, "\n", 1);
}