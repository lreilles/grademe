/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:12:15 by lsellier          #+#    #+#             */
/*   Updated: 2024/12/11 09:57:13 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	atoi(char *str)
{
	int	n;

	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n);
}

void	ft_putnbr(int nbr)
{
	if ((nbr / 10))
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

int	ft_is_prime(int test)
{
	int	jsp;

	jsp = 2;
	if (test < jsp)
		return (0);
	while (jsp < test)
	{
		if ((test % jsp) == 0)
			return (0);
		jsp++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	nb;
	int	a;
	int	i;

	nb = 0;
	i = 2;
	if (ac == 2 && av[1][0] != '-')
	{
		a = atoi(av[1]);
		while (i <= a)
		{
			if (ft_is_prime(i))
			{
				nb += i;
			}
			i++;
		}
		ft_putnbr(nb);
	}
	else
		ft_putchar('0');
	ft_putchar('\n');
	return (0);
}
