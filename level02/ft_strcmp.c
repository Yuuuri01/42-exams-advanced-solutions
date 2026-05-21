# include <stdio.h>


int    ft_strcmp(char *s1, char *s2)
{
    if(!s1 || !s2) return 0;
    while(*s1 && *s2)
    {
        if(*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    if(!*s1 && !*s2) return (0);
    return (*s1 - *s2);
}
int main()
{
    char *s1 = "abcb";
    char *s2 = "abcb";

    printf("%d\n", ft_strcmp(s1, s2));
}