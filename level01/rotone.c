# include <unistd.h>



int main(int ac, char **av)
{
	if(ac == 2)
	{
		char c;
		while(*av[1])
		{
			c = *av[1];
			if(c >= 'a' && c <= 'z')
			{
				if(c == 'z')
					c -= 25;
				else
					c += 1;

			}
			else if(c >= 'A' && c <= 'Z')
			{
				if(c == 'Z')
					c -= 25;
				else
					c += 1;
			}
							
			write(1, &c, 1);
			av[1]++;
		}
	}
	write(1, "\n", 1);
}
