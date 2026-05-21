# include <stdio.h>



unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int tmp;
    unsigned int total = a * b;
    while(b)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return total / a;
}
int main()
{
    printf("%d\n", lcm(6, 12));
}
