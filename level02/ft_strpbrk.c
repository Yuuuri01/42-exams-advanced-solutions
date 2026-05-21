# include <stdio.h>


char *ft_strpbrk(const char *s, const char *accept)
{
    char *accept2;
    char *new;


    new = (char *)s;
    while(*new)
    {
        accept2 = (char *)accept;
        while(*accept2)
        {
            if(*accept == *new)
                return &(*new);
            accept2++;
        }
        new++;
    }
    return NULL;
}
int main()
{
    char *s = "hellolok";
    char *accept = ".";
    char *new = ft_strpbrk(s, accept);
    if(new)
        printf("%s\n", new);
    else
        printf("NOT FOUND\n");
}