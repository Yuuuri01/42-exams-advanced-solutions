# include <unistd.h>
# include <stdio.h>


int ft_atoi(char *s)
{
    int res = 0;
    while(*s == 32 || *s == 9)
        s++;
    while(*s >= '0' && *s <= '9')
    {
        res = res * 10 + *s - 48;
        s++;
    }
    return res;
}
void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    char c = ((nb % 10) + 48);
        write(1, &c, 1);
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int nb = ft_atoi(av[1]);
        int i = 1;
        int j;
        while(i < 10)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(nb);
            write(1, " = ", 3);
            ft_putnbr(i * nb);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}