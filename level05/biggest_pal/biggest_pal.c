# include <unistd.h>

int get_len(char *str, int left, int right)
{
    while(left >= 0 && str[right] && str[left] == str[right])
    {
        left--;
        right++;
    }
    return (right - left - 1);
}
void biggest_pal(char *str)
{
    int len1;
    int len2;
    int final_len;
    int max;
    int i;
    int from;

    max = 0;
    i = 0;
    while(str[i])
    {
        len1 = get_len(str, i, i);
        len2 = get_len(str, i, i + 1);
        if(len1 > len2)
            final_len = len1;
        else
            final_len = len2;
        if(final_len >= max)
        {
            max = final_len;
            from = i - (final_len - 1) / 2;
        }
        i++;
    }
    i = 0;
    while(i < max)
        write(1, &str[from + (i++)], 1);
}
int main(int ac, char **av)
{
    if(ac == 2)
        biggest_pal(av[1]);
    write(1, "\n", 1);
}