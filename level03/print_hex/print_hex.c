# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_atoi(char *s)
{
    int res = 0;
    int sign = 1;
    while(*s == 32 || *s == 9)
        s++;
    while(*s == 45 || *s == 43)
    {
        if(*s == 45)
            sign *= -1;
        s++;
    }
    while(*s >= '0' && *s <= '9')
    {
        res = res * 10 + *s - 48;
        s++;
    }
    return res * sign;
}
void print_hex(int nb)
{
    char *base;
    base = "0123456789abcdef";
    if(nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if(nb > 9)
        print_hex(nb / 16);
    if(nb % 16 != 0)
        ft_putchar(base[nb % 16]);
}
int main (int ac, char **av)
{
    if(ac == 2)
    {
        int nb = ft_atoi(av[1]);
        print_hex(nb);
        write(1, "\n", 1);
    }
}