#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*temp;
	int		jsp;

	i = 0;
	j = 0;
	jsp = 0;
	if (ac >= 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		j = i;
		while (av[1][j] && (av[1][j] != ' ' && av[1][j] != '\t'))
		{
			j++;
		}
		temp = malloc(sizeof(char) * (j + 1));
		if (!temp)
			return (1);
		temp[j] = '\0';
		j = 0;
		while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
		{
			temp[j] = av[1][i];
			j++;
			i++;
		}
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
			{
				i++;
				if (av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t')
					ft_putchar(' ');
			}
			while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
			{
				ft_putchar(av[1][i]);
				i++;
				if (jsp == 0)
					jsp = 1;
			}
		}
	}
	if (temp[0] != '\0' && ac >= 2)
	{
		if (jsp == 1)
			ft_putchar(' ');
		ft_putstr(temp);
	}
	ft_putchar('\n');
	return (0);
}
