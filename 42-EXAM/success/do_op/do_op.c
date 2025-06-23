#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nbr)
{
	int	sign;
	int	taille;

	taille = 0;
	sign = 1;
	if (nbr < 0)
	{
		ft_putchar('-');
		sign *= -1;
	}
	if (nbr / 10)
		taille += ft_putnbr(((nbr / 10) * sign));
	taille += ft_putchar(((nbr % 10) * sign) + '0');
	return (taille);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 4)
	{
		if (av[2][0] == '*')
			ft_putnbr(atoi(av[1]) * atoi(av[3]));
		else if (av[2][0] == '+')
			ft_putnbr(atoi(av[1]) + atoi(av[3]));
		else if (av[2][0] == '-')
			ft_putnbr(atoi(av[1]) - atoi(av[3]));
		else if (av[2][0] == '/')
			ft_putnbr(atoi(av[1]) / atoi(av[3]));
		else if (av[2][0] == '%')
			ft_putnbr(atoi(av[1]) % atoi(av[3]));
	}
	ft_putchar('\n');
	return (0);
}
