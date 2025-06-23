#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c <= 13 && c >= 9)
		return (1);
	return (0);
}
int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (ft_isspace(av[1][i]) && av[1][i])
			i++;
		while (av[1][i])
		{
			if (ft_isspace(av[1][i]) && av[1][i])
			{
				while (ft_isspace(av[1][i]) && av[1][i])
					i++;
				if (av[1][i] != '\0')
				{
					ft_putchar(' ');
					ft_putchar(' ');
					ft_putchar(' ');
				}
			}
			else
			{
				ft_putchar(av[1][i]);
				i++;
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
