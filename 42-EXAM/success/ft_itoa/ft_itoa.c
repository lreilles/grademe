/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:59:47 by lsellier          #+#    #+#             */
/*   Updated: 2024/12/11 10:24:46 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*str;
	int		temp;
	int		taille;
	int		i;
	int		p;

	p = 1;
	taille = 1;
	temp = nbr;
	if (nbr < 0)
	{
		p *= -1;
		taille++;
	}
	while ((temp * p) / 10)
	{
		taille++;
		temp = temp / 10;
	}
	str = malloc((taille + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = taille - 1;
	str[taille] = '\0';
	while (i >= 0)
	{
		str[i] = (((nbr) % 10) * p) + '0';
		nbr = nbr / 10;
		i--;
	}
	if (p == -1)
	{
		str[0] = '-';
	}
	return (str);
}

// int	main(int ac, char **av)
// {
// 	printf("%s\n", ft_itoa(2147483647));
// 	return (0);
// }
