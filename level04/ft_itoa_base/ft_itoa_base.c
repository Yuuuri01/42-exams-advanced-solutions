# include <unistd.h>
# include <stdlib.h>


int get_len(int nb, int base)
{
    int size = 0;
    unsigned int tmp;
    if(nb == 0)
        return 1;
    if(base == 10 && nb < 0)
    {
        tmp = -nb;
        size++;
    }
    else
        tmp = (unsigned int)nb;

    while(tmp)
    {
        size++;
        tmp /= base;
    }
    return size;
}
char    *ft_itoa_base(int value, int base)
{
    char *s;
    int size;
    unsigned int nbr;
    char *full_base;
    if(base < 2 || base > 16)
    {
        char *empty;
        empty = malloc(1 * sizeof(char));
        if(!empty)
            return NULL;
        empty[0] = '\0';
        return empty;
    }
    full_base = "0123456789ABCDEF";
    size = get_len(value, base);
    s = malloc((size + 1) * sizeof(char));
    if(!s) return NULL;

    if(value < 0 && base == 10)
    {
        s[0] = '-';
        nbr = -value;
    }
    else
        nbr = value;
    s[size--] = '\0';
    while(size >= 0)
    {
        s[size--] = full_base[nbr % base];
        nbr /= base;
    }
    return s;
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        int val = atoi(av[1]);
        int base = atoi(av[2]);
        char *s = ft_itoa_base(val, base);
        int len = 0;

        while(s[len])
            len++;
        write(1, s, len);
        if(s)
            free(s);
    }
    write(1, "\n", 1);
}
