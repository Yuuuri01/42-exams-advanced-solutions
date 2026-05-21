# include <unistd.h>



int main(int ac, char **av)
{
    if(ac == 3)
    {
        int len = 0;
        while(av[1][len])
            len++;
        int j = 0;
        int i = 0;
        while(av[2][i])
        {
            if(av[1][j] && av[2][i] == av[1][j])
                j++;
            i++;
        }
        if(j == len)
            write(1, "1\n", 2);
        else
            write(1, "0\n", 2);
    }
}
