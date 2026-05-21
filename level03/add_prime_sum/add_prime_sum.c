# include <unistd.h>
# include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb == 0)
    {
        ft_putchar('0');
        return;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);        
}
int ft_atoi(char *str)
{
    int res = 0;
    while(*str == 32)
        str++;
    while(*str)
        res = res * 10 + *(str++) - 48;
    return res; 
}




int is_prime(int nb)
{
    if(nb <= 1)
        return 0;

    int i = 2;
    while(i * i <= nb)
    {
        if(nb % i == 0)
            return 0;
        i++;
    }
    return 1;
}
int main(int ac, char **av)
{
    if(ac != 2)
    {
        write(1, "0\n", 2);
        exit(EXIT_SUCCESS);
    }
    if(ac == 2)
    {
        int nb = ft_atoi(av[1]);
        if(nb <= 1)
        {
            write(1, "0\n", 2);
            exit(EXIT_SUCCESS);
        }
        int res = 0;
        int i = 2;
        while(i <= nb)
        {
            if(is_prime(i))
                res += i;
            i++;
        }
        ft_putnbr(res);
        write(1, "\n", 1);
    }
    exit(EXIT_SUCCESS);
}