# include "head.h"


int is_op(char *s, int *sign)
{
    if(s[1])
    {
        *sign = -1;
        return 0;
    }
    if(s[0] == '+' || s[0] == '-' || s[0] == '/' || s[0] == '%' || s[0] == '*')
        return 1;

    //false characters
    *sign = -1;
    return 0;
}
int is_nb(char *s)
{
    if((s[1] >= '0' && s[1] <= '9') && (s[0] == '+' || s[0] == '-'))
        return 1;
    return (s[0] >= '0' && s[0] <= '9');
}
void rpn_calc(char *av)
{
    int i;
    int k;
    int sign;
    int stack[500];
    int access = 0;
    char **numbers;

    i = 0;
    k = -1;
    sign = 1;
    numbers = ft_split(av);
    if(!numbers)
    {
        write(1, "Error", 5);
        return;
    }
    
    while(numbers[i])
    {
        if(is_nb(numbers[i]))
            stack[++k] = atoi(numbers[i]);
        else if(is_op(numbers[i], &sign))
            do_op(stack, &k, numbers[i][0], &sign);
        if(sign == -1)
        {
            write(1, "Error", 5);
            return;
        }
        i++;
    }
    if(k == 0)
    {
        ft_putnbr(stack[0]);
        return;
    }
    write(1, "Error", 5);
}