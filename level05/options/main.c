# include "head.h"
# include <unistd.h>

int main(int ac, char **av)
{
    if(ac >= 2)
    {
        char **op = av + 1;
        options(op);
    }
    else
        write(1, "00000000 00000000 00000000 00000000", 35);
    write(1, "\n", 1);
}