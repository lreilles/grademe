/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:18:34 by lsellier          #+#    #+#             */
/*   Updated: 2025/03/12 08:10:10 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int	a;
	int	res;

	res = 0;
	a = 1;
	if (n < 0)
	{
		a *= -1;
		res++;
		ft_putchar('-');
	}
	if (n / 10)
		res += ft_putnbr((n / 10) * a);
	res += ft_putchar((n % 10) * a + '0');
	return (res);
}

int	ft_putstr(char *str)
{
	int	res;

	res = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		res += ft_putchar(*str++);
	return (res);
}

int	ft_puthex(unsigned int n)
{
	int		res;
	char	hex[16] = "0123456789abcdef";

	res = 0;
	if (n / 16)
		res += ft_puthex(n / 16);
	res += ft_putchar(hex[n % 16]);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	args;

	res = 0;
	if (!str)
		return (res);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
				res += ft_putnbr(va_arg(args, int));
			else if (*str == 's')
				res += ft_putstr(va_arg(args, char *));
			else if (*str == 'x')
				res += ft_puthex(va_arg(args, unsigned int));
		}
		else
			res += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (res);
}

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	printf("\nrésultat de ft_printf = %d\n", ft_printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648));
// 	printf("\nrésultat de ft_printf = %d\n", printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648));
// 	return (0);
// }
