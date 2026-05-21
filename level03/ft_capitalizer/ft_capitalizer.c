# include <unistd.h>



void ft_capitalizer(char *s)
{
    char c;
    int first = 1;
    int upper_now = 1;
    while(*s)
    {
        c = *s;
        if(c == 32)
            upper_now = 1;
        else if(upper_now)
        {
            if(c >= 'a' && c <= 'z')
                c -= 32;
            upper_now = 0;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            c += 32;
            write(1, &c, 1);
        }
        write(1, &c, 1);
        s++;
    }
}
int main(int ac, char **av)
{
    if(ac >= 2)
    {
        int i = 1;
        while(i < ac)
        {
            ft_capitalizer(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}