# include <unistd.h>


int main(int ac, char **av)
{
	if(ac == 2)
	{
		while(*av[1] == 32)
			av[1]++;
		int i = 0;
		while(av[1][i] && av[1][i] != 32)
			i++;
		write(1, av[1], i);
	}
	write(1, "\n", 1);
}
