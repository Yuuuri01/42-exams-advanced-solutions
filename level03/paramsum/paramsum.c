# include <unistd.h>


int main(int ac, char **av)
{
    char c = ((ac - 1) % 10) + 48;
    write(1, &c, 1);
    write(1, "\n", 1);
}
