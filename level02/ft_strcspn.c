# include <stddef.h>

size_t ft_strcspn(char *s, const char *reject)
{
    size_t i = 0;
    int j;
    while(s[i])
    {
        j = 0;
        while(reject[j])
        {
            if(reject[j] == s[i])
                return i;
            j++;
        }
        i++;
    }
    return i;
}
# include <stdio.h>
int main()
{
    char *s = "hello,world";
    char *reject = ",";
    printf("%lu\n", ft_strcspn(s, reject));
}