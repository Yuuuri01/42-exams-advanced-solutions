# include <unistd.h>



int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *s;
        int i = 0;
        int j = 0;
        int sp = 0;
        int sp2 = 0;
        while(av[1][i] && (av[1][i] == 32 || av[1][i] == 9))
            i++;

        s = &av[1][i];
        while(av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
        {
            i++;
            j++;
        }
        if(av[1][i])
            av[1][i++] = '\0';

        while(av[1][i]) 
        {   
            if(av[1][i] != 32 && av[1][i] != 9)
            {
                if(sp)
                {
                    write(1, " ", 1);
                    sp = 0;
                }
                write(1, &av[1][i], 1);
                sp2 = 1;
            }
            else if(av[1][i] == 9 || av[1][i] == 32)
                sp = 1;
            i++;
        }
        if(sp2)
            write(1, " ", 1);
        write(1, s, j);
    }
    write(1, "\n", 1);
}