# include <unistd.h>

void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    char c = (nb % 10) + 48;
    write(1, &c, 1);
}