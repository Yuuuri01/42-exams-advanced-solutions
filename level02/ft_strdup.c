# include <stdlib.h>
# include <stdio.h>

char *ft_strdup(const char *str)
{
    int len;
    char *new;
    char *send;

    if(!str) return NULL;
    len = 0;
    while(str[len]) len++;
    if(!(new = malloc((len + 1) * sizeof(char)))) return NULL;
    send = new;

    while(*str) *new++ = *str++;
    *new = '\0';

    return send;
}   
int main()
{
    char *s = "hello";

    printf("%s\n", ft_strdup(s));
}