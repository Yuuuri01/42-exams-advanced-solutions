# include <unistd.h>

void ft_putnbr(int nb)
{
	if(nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if(nb > 9)
		ft_putnbr(nb / 10);
	char n = (nb % 10) + 48;
	write(1, &n, 1);
}
void print_tab(int *tab, int size)
{
	int i = 0;
	while(i < size)
	{
		ft_putnbr(tab[i++]);
		if(i != size)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
int quick_sort(int *arr, int start, int end)
{
	int tmp;
	int j = start - 1;
	int i = start;
	while(i < end)
	{
		if(arr[i] < arr[end])
		{
			j++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		i++;
	}
	if(j + 1 < end)
	{
		tmp = arr[j + 1];
		arr[j + 1] = arr[end];
		arr[end] = tmp;
	}
	return (j + 1);
}
void recursive_sort(int *arr, int from, int end)
{
	if(from > end)
		return;
	else
	{
		int from_to = quick_sort(arr, from, end);

		recursive_sort(arr, from, from_to - 1);
		recursive_sort(arr, from_to + 1, end);
	}
}
void sort_int_tab(int *tab, unsigned int size)
{
	recursive_sort(tab, 0, size - 1);
}
int main()
{
	int arr[] = {8, 2, 4, 7, 1, 3, 9, 6, 5};
	print_tab(arr, 9);
	sort_int_tab(arr, 9);
	print_tab(arr, 9);

}
