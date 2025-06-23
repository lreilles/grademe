/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:04:32 by lsellier          #+#    #+#             */
/*   Updated: 2024/12/11 13:10:30 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				j = 0;
				while (j <= (av[1][i] - 'a'))
				{
					ft_putchar(av[1][i]);
					j++;
				}
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				j = 0;
				while (j <= (av[1][i] - 'A'))
				{
					ft_putchar(av[1][i]);
					j++;
				}
			}
			else
				ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
