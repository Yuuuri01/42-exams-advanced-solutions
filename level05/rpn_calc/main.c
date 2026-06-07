# include "head.h"


int main(int ac, char **av)
{
    if(ac == 2)
    {
        rpn_calc(av[1]);
    }
    else
        write(1, "Error",5);
    write(1, "\n", 1);
}