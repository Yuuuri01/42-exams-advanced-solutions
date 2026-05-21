# include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
int main(int ac, char **av)
{
	if(ac == 2)
	{
		int i;
		char c;
		while(*av[1])
		{
			c = *av[1];
			if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{ 
				i = (c >= 'a' && c <= 'z') ? ((c - 'a') % 26) : ((c - 'A') % 26);
				while(i-- >= 0)
					write(1, &c, 1);
			}
			else
				ft_putchar(c);
			av[1]++;
		}

	}
	ft_putchar('\n');

}
