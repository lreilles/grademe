#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				ft_putchar((((av[1][i] - 'a') + 13) % 26) + 'a');
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				ft_putchar((((av[1][i] - 'A') + 13) % 26) + 'A');
			}
			else
			{
				ft_putchar(av[1][i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
