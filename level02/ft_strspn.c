
int ft_strspn(char *s1, char *s2)
{
    char tab[256] = {0};
    int len;
    while(*s2)
        tab[(unsigned char)*s2++] = 1;

    len = 0;
    while(*s1)
    {
        if(tab[(unsigned char)*s1] == 1)
            len++;
        else
            return len;
        s1++;
    }
    return len;
}
# include <stdio.h>
int main()
{
    char *s1 = "abc";
    char *s2 = "aaabbbccc";
    // char *str1 = "12345d6789";
    // char *str2 = "123456789";
    printf("%d\n", ft_strspn(s1, s2));
}