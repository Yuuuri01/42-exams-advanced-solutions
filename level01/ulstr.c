# include <unistd.h>



int main(int ac, char **av)
{
	if(ac == 2)
	{
		char c;
		while(*av[1])
		{
			c = *av[1];
			if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
				c = c ^ 32;
			write(1, &c, 1);
			av[1]++;
		}
	}
	write(1, "\n", 1);
}
