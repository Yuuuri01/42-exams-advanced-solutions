# include <unistd.h>


int count_alpha(char c, char *str)
{
    int count = 0;
    while(*str)
    {
        if(*str == c)
            count++;
        str++;
    }
    return count;
}
void ft_putnbr(int nb)
{
    char c;
    if(nb > 9)
        ft_putnbr(nb / 10);
    c = (nb % 10) + 48;
    write(1, &c, 1);
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int c;
        int access = 1;
        char ascii[256] = {0};
        while(*av[1])
        {
            if((*av[1] >= 'a' && *av[1] <= 'z') || (*av[1] >= 'A' && *av[1] <= 'Z'))
            {
                c = count_alpha(*av[1], av[1]);
                if(c != 0 && !ascii[(unsigned char)*av[1]])
                {
                    if(!access)
                        write(1, ", ", 2);
                    ft_putnbr(c);
                    write(1, &(*av[1]), 1);
                    ascii[(unsigned char)*av[1]] = 1;
                    access = 0;
                }
            }
            av[1]++;
        }
    }
    write(1, "\n", 1);
}