# include <unistd.h>


// int	    is_power_of_2(unsigned int n)
// {
    
//     unsigned int i = 1;
//     if(n == 0)
//         return 0;
//     while(i < n)
//         i *= 2;

//     return (i == n) ? 1 : 0;
// }
int	    is_power_of_2(unsigned int n)
{
    if(n == 0)
        return 0;
    return ((n & (n - 1)) == 0);
}
# include <stdio.h>
int main()
{
    printf("%d\n", is_power_of_2(5));
}
