# include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c, 1);	
}
void ft_putnbr(int nb)
{
	if(nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if(nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if(nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}
int ft_atoi(char *str)
{
	int res = 0;
	int sign = 1;
	while(*str == 32)
		str++;
	if(*str == 45 || *str == 43)
	{
		if(*str == 45)
			sign = -sign;
		str++;
	}
	while(*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return res * sign;
}

# include <stdio.h>
int main(int ac, char **av)
{
	if(ac != 4)
	{
		write(1, "\n", 1);
		return 0;
	}
	if(av[2][1] != '\0')
	{
		write(1, "\n", 1);
		return 0;
	}
	if(av[2][0] != '-' && av[2][0] != '+' && av[2][0] != '*' && av[2][0] != '/' && av[2][0] != '%')
	{
		write(1, "\n", 1);
		return 0;
	}
	char op = av[2][0];
	int nb1 = ft_atoi(av[1]);
	int nb2 = ft_atoi(av[3]);
	int res = 0;

	if(op == '+') res = nb1 + nb2;
	else if(op == '-') res = nb1 - nb2;
	else if(op == '*') res = nb1 * nb2;
	else if(op == '/')
	{
		if(nb2 == 0) return (printf("stop : devision by zero\n"), 0);
		res = nb1 / nb2;
	}
	else if(op == '%')
	{
		if(nb2 == 0) return (printf("stop : modulo by zero\n"), 0);
		res = nb1 % nb2;
	}
	ft_putnbr(res);
	write(1, "\n", 1);
}


