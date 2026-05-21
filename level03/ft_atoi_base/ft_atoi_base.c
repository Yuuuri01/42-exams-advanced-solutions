


int get_position(char c, int str_base)
{
    char *base;
    int pos;

    base = "0123456789abcdef";
    pos = 0;
    while(base[pos])
    {
        if(base[pos] == c || (base[pos] - 32) == c)
        {
            if(pos >= str_base)//that character is't in base?
                return -1;
            return pos;
        }
        pos++;
    }
    return -1;
}
int	ft_atoi_base(const char *str, int str_base)
{
    int sign;
    int val;
    int res;
    if(str_base > 16 || str_base < 2)
        return 0;

    res = 0;
    sign = 1;
    while(*str == 32 || *str == 9 || *str == 13)
        str++;
    if(*str == 45 || *str == 43)
    {
        if(*str == 45)
            sign = -sign;
        str++;
    }
    while(*str)
    {
        val = get_position(*str, str_base);
        if(val != -1)
            res = res * str_base + val;
        else
            return res * sign;
        str++;
    }
    return res * sign;
}
# include <stdio.h>
#include <stdio.h>

// main dial l-test
int main(void)
{
    printf("--- 1. (NORMAL)---\n");
    printf("Base 10 (\"10\")    : %d (Expected: 10)\n", ft_atoi_base("10", 10));
    printf("Base 2  (\"1010\")  : %d (Expected: 10)\n", ft_atoi_base("1010", 2));
    printf("Base 16 (\"ff\")    : %d (Expected: 255)\n", ft_atoi_base("ff", 16));
    printf("Base 16 (\"FF\")    : %d (Expected: 255)\n", ft_atoi_base("FF", 16));
    printf("Base 16 (\"1A\")    : %d (Expected: 26)\n", ft_atoi_base("1A", 16));

    printf("\n--- 2. (SIGNS) ---\n");
    printf("Minus   (\"-10\")   : %d (Expected: -10)\n", ft_atoi_base("-10", 10));
    printf("Plus    (\"+42\")   : %d (Expected: 42)\n", ft_atoi_base("+42", 10));
    printf("Joj     (\"--10\")  : %d (Expected: 0)\n", ft_atoi_base("--10", 10));

    printf("\n--- 3. WHITESPACES W CHARACTERS not in base ---\n");
    printf("Spaces  (\"   12\") : %d (Expected: 12)\n", ft_atoi_base("   12", 10));
    printf("Ghalt f Base 10 (\"12f3\"): %d (Expected: 12)\n", ft_atoi_base("12f3", 10));
    printf("Ghalt f Base 2  (\"1021\"): %d (Expected: 2)\n", ft_atoi_base("1021", 2));

    printf("\n--- 4. L-BASES (ERRORS) ---\n");
    printf("Base > 16  (\"10\", 17): %d (Expected: 0)\n", ft_atoi_base("10", 17));
    printf("Base < 2   (\"10\", 1) : %d (Expected: 0)\n", ft_atoi_base("10", 1));
    return (0);
}
