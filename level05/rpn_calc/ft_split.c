# include "head.h"

int count_words(char *s)
{
    int i = 0;
    int count = 0;
    while(s[i])
    {
        if(s[i] != ' ' && s[i] != '\t')
        {
            if((i == 0 || (s[i - 1] == ' ' || s[i - 1] == '\t')))
                count++;
        }
        i++;
    }
    return count;
}
int len_word(char *s)
{
    int i = 0;
    while(s[i] && (s[i] != ' ' && s[i] != '\t'))
        i++;
    return i;
}
char *copy_word(char *s, int len)
{

    int i;
    char *str = malloc((len + 1) * sizeof(char));
    if(!str)
        return NULL;
    i = 0;
    while(s[i] && i < len)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
char **ft_split(char *s)
{
    char **str;
    int i;
    int j;
    int length;
    int index;

    str = malloc((count_words(s) + 1) * sizeof(char *));
    if(!str)
        return NULL;

    i = 0;
    index = 0;
    length = 0;
    while(s[i])
    {
        if(s[i] != ' ' && s[i] != '\t')
        {
            length = len_word(&s[i]);
            str[index] = copy_word(&s[i], length);
            if(!str[index])
            {
                j = 0;
                while(j <= index)
                    free(str[j++]);
                free(str);
                return NULL;
            }
            i += length;
            index++;
        }
        else
            i++;
    }
    str[index] = NULL;
    return str;
}