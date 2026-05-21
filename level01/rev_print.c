# include <unistd.h>


int main(int ac, char **av)
{
	if(ac == 2)
	{
		int len;
		len = 0;
		while(av[1][len]) len++;

		len -= 1;
		while(av[1][len])
			write(1, &av[1][len--], 1);
	}
	write(1, "\n", 1);
}
