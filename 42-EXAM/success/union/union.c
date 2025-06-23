/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:13:26 by lsellier          #+#    #+#             */
/*   Updated: 2024/12/11 13:31:26 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	est_deja_ecris(char *src1, int i)
{
	int	temp;

	temp = i;
	i--;
	while (i >= 0)
	{
		if (src1[temp] == src1[i])
			return (1);
		i--;
	}
	return (0);
}

int	est_deja_ecris2(char *src1,char *src2, int i)
{
	int	temp;

	temp = 0;
	while (src1[temp])
	{
		if (src2[i] == src1[temp])
			return (1);
		temp++;
	}
	return (0);
}

int	est_dedans(char *src1, char *src2, int i)
{
	int	j;

	j = 0;
	if (!est_deja_ecris(src1, i))
	{
		while (src2[j])
		{
			if (src1[i] == src2[j])
				return (1);
			j++;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (est_dedans(av[1], av[2], i))
				ft_putchar(av[1][i]);
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if (!est_deja_ecris(av[2], i))
			{
				if (!est_deja_ecris2(av[1], av[2], i))
					ft_putchar(av[2][i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
