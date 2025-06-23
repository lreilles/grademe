/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:04:12 by lsellier          #+#    #+#             */
/*   Updated: 2024/12/11 13:04:13 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nbr)
{
	int	sign;
	int	taille;

	sign = 1;
	if (nbr < 0)
	{
		sign *= -1;
		ft_putchar('-');
		taille++;
	}
	if (nbr / 10)
		taille += ft_putnbr((nbr / 10) * sign);
	taille += ft_putchar(((nbr % 10) * sign) + '0');
	return (taille);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		taille;
	int		temp;
	int		fin;
	int		sign;

	taille = 1;
	fin = 0;
	sign = 1;
	temp = nbr;
	while (temp / 10)
	{
		temp = temp / 10;
		taille++;
	}
	if (nbr < 0)
	{
		taille++;
		fin = 1;
		sign *= -1;
	}
	str = malloc((taille + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[taille + 1] = '\0';
	if (nbr < 0)
		str[0] = '-';
	while (taille > fin)
	{
		str[taille - 1] = ((nbr % 10) * sign) + '0';
		nbr = nbr / 10;
		taille--;
	}
	return (str);
}
