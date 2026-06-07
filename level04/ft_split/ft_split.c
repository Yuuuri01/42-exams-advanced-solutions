# include <stdlib.h>


int check_char(char c)
{
    if(c == ' ' || c == '\t' || c == '\n')
        return 1;
    return 0;
}
int count_words(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(s[i])
    {
        if(!check_char(s[i]))
        {
            if(i == 0 || check_char(s[i - 1]))
                count++;
        }
        i++;
    }
    return count;
}
int len_word(char *s)
{
    int len;
    len = 0;
    while(s[len] && !check_char(s[len]))
        len++;

    return len;
}
char *copy(char *s, int len)
{
    int i;
    char *new = malloc((len + 1) * sizeof(char));
    if(!new)
        return NULL;
    i = 0;
    while(s[i] && i < len)
    {
        new[i] = s[i];
        i++;
    }
    new[i] = '\0';
    return new;
}
char    **ft_split(char *str)
{
    char **s;
    int len;
    int i;
    int j;

    if(!str)
        return NULL;
    s = malloc((count_words(str) + 1) * sizeof(char *));
    if(!s)
        return NULL;

    i = 0;
    j = 0;
    len = 0;
    while(str[i])
    {
        if(!check_char(str[i]))
        {
            len = len_word(&str[i]);
            s[j] = copy(&str[i], len);
            if(!s[j])
            {
                i = 0;
                while(i <= j)
                    free(s[i++]);
                free(s);
                return NULL;
            } 
            j++;
            i += len;
        }
        else
            i++;
    }
    s[j] = NULL;
    return s;
}