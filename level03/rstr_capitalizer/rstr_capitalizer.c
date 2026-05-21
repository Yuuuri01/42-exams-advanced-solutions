# include <unistd.h>


void rstr_capitalizer(char *av)
{
    char c;
    while(*av)
    {
        c = *av;
        if(*(av + 1) && (*(av + 1) == 32) || (*(av + 1) == '\0'))
        {
            if(c >= 'a' && c <= 'z')
            {
                c -= 32;
                write(1, &c, 1);
            }
            else
                write(1, &c, 1);
        }
        else if(c >= 'A' && c <= 'Z')
        {
            c += 32;
            write(1, &c, 1);
        }
        else
            write(1, &c, 1);
        av++;
    }
}
int main(int ac, char **av)
{
    if(ac >= 2)
    {
        int i = 1;
        while(*av[i])
        {
            rstr_capitalizer(av[i++]);
            write(1, "\n", 1);
        }
    }
    else
        write(1, "\n", 1);
}