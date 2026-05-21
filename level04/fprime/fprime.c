# include <unistd.h>
# include <stdlib.h>

void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        write(1, "-", 1);
        return ;
    }
    else if(nb > 9)
        ft_putnbr(nb / 10);
    char c = nb % 10 + 48;
    write(1, &c, 1);
}
int ft_atoi(char *s)
{
    int res = 0;
    while(*s == 32 || *s == 9)
        s++;
    while(*s >= '0' && *s <= '9')
        res = res * 10 + *(s++) - 48;
    return res
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int nb = ft_atoi(av[1]);
        int i = 2;
        while(nb > 1)
        {
            if(nb % i == 0)
            {
                ft_putnbr(i);
                nb /= i;
                if(nb > 1)
                    write(1, "*", 1);
            }
            else
                i++;
        }
    }
    write(1, "\n", 1);
}
