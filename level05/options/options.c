# include <unistd.h>
# include "head.h"


void options(char **av)
{
    int j;
    int val;
    int i = 0;
    int res = 0;
    if(!check_valid(av))
    {
        write(1, "Invalid Option\n", 15);
        return;
    }
    while(av[i])
    {
        j = 1;
        while(av[i][j])
        {
            if(av[i][j] == 'h')
            {
                write(1, "options: abcdefghijklmnopqrstuvwxyz", 35);
                return;
            }
            val = get_position(av[i][j]);
            if(val != -1)
                res = res | (1 << val);
            else
            {
                write(1, "Invalid Option\n", 15);
                return;
            }
            j++;
        }
        i++;
    }
    i = 31;
    while(i >= 0)
    {
        if((res >> i) & 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        if(i % 8 == 0 && i != 0)
            write(1, " ", 1);
        i--;
    }
}