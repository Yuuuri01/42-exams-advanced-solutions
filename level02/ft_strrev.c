# include <stdio.h>


char    *ft_strrev(char *str)
{
    char *tmp;
    char *s;

    s = str;
    while(*s && *(s + 1)) s++;

    tmp = str;
    while(tmp < s)
    {
        *tmp ^= *s;
        *s ^= *tmp;
        *tmp++ ^= *s--;
    }
    return str;
}
int main()
{
    char str[] = "12345";
    printf("%s\n", ft_strrev(str));
}