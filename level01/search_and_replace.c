# include <unistd.h>



int main(int ac, char **av)
{
	if(ac == 4)
	{
		if(av[2][1] != '\0' || av[3][1] != '\0')
		{
			write(1, "\n", 1);
			return 0;
		}
		char c;
		while(*av[1])
		{
			c = *av[1];
			if(c == *av[2])
				c = *av[3];
			write(1, &c, 1);
			av[1]++;
		}

	}
	write(1, "\n", 1);
}
