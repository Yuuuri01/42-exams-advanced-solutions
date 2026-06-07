# include <stdlib.h>
# include <stdio.h>


int check_char(char c)
{
    return(c == ' ' || c == '\t' || c == '\n');
}
int count_word(char *str)
{
    int counter = 0;
    int i = 0;
    while(str[i])
    {
        if(!check_char(str[i]))
        {
            if(i == 0 || check_char(str[i - 1]))
                counter++;
        }
        i++;
    }
    return counter;
}
char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **sp;
    int len;

    if(!str)
        return NULL;
    sp = malloc((count_word(str) + 1) * sizeof(char *));
    if(!sp)
        return NULL;
    while(str[i])
    {
        if(!check_char(str[i]))
        {
            k = i;
            len = 0;
            while(str[k] && !check_char(str[k]))
            {
                len++;
                k++;
            }
            k = 0;
            if(!(sp[j] = malloc((len + 1) * sizeof(char))))
            {
                while(k < j)
                    free(sp[k++]);
                free(sp);
                return NULL;
            }
            while(str[i] && !check_char(str[i]))
                sp[j][k++] = str[i++];
            sp[j++][k] = '\0';
        }
        else
        {
            while(str[i] && check_char(str[i]))
                i++;
        }
    }
    sp[j] = NULL;
    return sp;
}
int main()
{
    char *s = "\t\nhello your \n\n klo world\n\t  ";
    char **s2 =  ft_split(s);
    int i = 0;
    while(s2[i])
    {
        printf("%s\n", s2[i]);
        free(s2[i]);
        i++;
    }
    free(s2);
}