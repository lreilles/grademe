/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:02:55 by lsellier          #+#    #+#             */
/*   Updated: 2024/12/10 13:27:50 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*buffer;
	int	i;

	i = 0;
	if (start <= end)
	{
		buffer = malloc((end - start + 1) * sizeof(int));
		while ((start + i) <= end)
		{
			buffer[i] = (start + i);
			i++;
		}
	}
	else
	{
		buffer = malloc((start - end + 1) * sizeof(int));
		while ((start - i) >= end)
		{
			buffer[i] = (start - i);
			i++;
		}
	}
	return (buffer);
}

// int	main(int ac, char **av)
// {
// 	int	*test;
// 	int	i;

// 	i = 0;
// 	test = ft_range((-1 * (av[1][0] - '0')), (-1 * (av[2][0] - '0')));
// 	while (test[i])
// 	{
// 		printf("%d\n", test[i]);
// 		i++;
// 	}
// 	return (0);
// }
