# include <unistd.h>

int check_palindrom(char *s, int from, int to)
{
    while(s[from] && from <= to && to >= 0)
    {
        if(s[from] != s[to])
            return 0;
        from++;
        to--;
    }
    return 1;
}
void    biggest_pal(char *str)
{
    int len;
    int j;
    int from;
    int max = 0;
    int i = 0;
    while(str[i])
    {
        j = i;
        while(str[j])
        {
            int val = check_palindrom(str, i, j);
            len = j - i + 1;
            if(val && len >= max)
            {
                max = len;
                from = i;
            }
            j++;
        }
        i++;
    }
    write(1, &(str[from]), max);
}
int main(int ac, char **av)
{
    if(ac == 2)
        biggest_pal(av[1]);
    write(1, "\n", 1);
}