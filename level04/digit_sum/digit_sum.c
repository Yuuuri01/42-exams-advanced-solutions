# include <unistd.h>


void ft_putnbr(int nb)
{
    if(nb > 9)
        ft_putnbr(nb / 10);
    char c = (nb % 10) + '0';
    write(1, &c, 1);
}
int digit_sum(int sum)
{
    int res = 0;
    while(sum)
    {
        res += sum % 10;
        sum /= 10; 
    }
    return res;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        
        int sum = 0;
        while(*av[1] == 32 || *av[1] == 9)
            av[1]++;
        if(*av[1] == 43)
            av[1]++;

        while(*av[1] && (*av[1] >= '0' && *av[1] <= '9'))
        {
            sum += *av[1] - 48;
            av[1]++;
        }
        sum = digit_sum(sum);
        while(sum > 9)
        {
            sum = digit_sum(sum);
        }
        ft_putnbr(sum);
    }
    write(1, "\n", 1);
}