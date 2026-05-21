int ft_atoi(const char *str)
{
    int res = 0;
    int sign = 1;
    while(*str == 32 || *str == 13 || *str == 9)
        str++;
    if(*str == 45 || *str == 43)
    {
        if(*str == 45)
            sign = -sign;
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        res = res * 10 + *str - 48;
        str++;
    }
    return res * sign;
}