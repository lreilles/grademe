/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 21:01:37 by fwuensch          #+#    #+#             */
/*   Updated: 2025/03/21 13:19:44 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned char	reverse_bits2(unsigned char octet)
{
	unsigned char	result;
	int				i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result = result | ((octet >> i) & 1) << (7 - i);
		i++;
	}
	return (result);
}

unsigned char	reverse_bits(unsigned char octet)
{
	return ((octet & 0x01) << 7 | (octet & 0x02) << 5 | (octet & 0x04) << 3 \
	| (octet & 0x08) << 1 | (octet & 0x10) >> 1 | (octet & 0x20) >> 3 \
	| (octet & 0x40) >> 5 | (octet & 0x80) >> 7);
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

// int	main(void)
// {
// 	int	test;

// 	test = 179;
// 	printf("%u\n", test);
// 	printf("%u\n", swap_bits2fdp(test));
// 	return (0);
// }
