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
unsigned int pgcd(unsigned int a, unsigned int b)
{
    unsigned int  total = 0;
    while(b)
    {
        total = a % b;// 42 % 10 == 2
        a = b; // 10 / 2
        b = total; // 2 / 0
    }
    return a;
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        int nb1 = ft_atoi(av[1]);
        int nb2 = ft_atoi(av[2]);
        unsigned int res = pgcd((unsigned int)nb1, (unsigned int)nb2);
        printf("%d", res);
    }
    printf("\n");

}