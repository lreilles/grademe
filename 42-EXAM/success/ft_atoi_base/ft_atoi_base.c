/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 04:04:55 by lsellier          #+#    #+#             */
/*   Updated: 2024/12/17 04:15:29 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	est_bon(char c, int str_base)
{
	char const	hex[16] = "0123456789abcdef";
	char const	hex2[16] = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < str_base)
	{
		if (c == hex[i] || c == hex2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int			res;
	int			sign;

	sign = 1;
	res = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (est_bon(*str, str_base) != -1)
	{
		if (*str >= 'A' && *str <= 'F')
			res = res * str_base + est_bon(*str, str_base);
		else
			res = res * str_base + est_bon(*str, str_base);
		str++;
	}
	return (sign * res);
}

// #include <stdlib.h>
// #include <stdio.h>

// int main(void)
// {
// 	printf("%i\n", ft_atoi_base("2A", 16));
// 	return(0);
// }
