/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsellier <lsellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:27:32 by lsellier          #+#    #+#             */
/*   Updated: 2024/12/12 04:08:10 by lsellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 	s_point {
	int 		x;				// x : Width  | x-axis
	int 		y;				// y : Height | y-axis
} 				t_point;

void	flood_fill2(char **tab, t_point size, t_point begin, char enculer)
{
	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
		return ;
	if (tab[begin.y][begin.x] != enculer)
		return ;
	tab[begin.y][begin.x] = 'F';
	flood_fill2(tab, size, (t_point){begin.x - 1, begin.y}, enculer);
	flood_fill2(tab, size, (t_point){begin.x + 1, begin.y}, enculer);
	flood_fill2(tab, size, (t_point){begin.x, begin.y - 1}, enculer);
	flood_fill2(tab, size, (t_point){begin.x, begin.y + 1}, enculer);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	flood_fill2(tab, size, begin, tab[begin.y][begin.x]);
}

// char** make_area(char** zone, t_point size)
// {
// 	char** new;

// 	new = malloc(sizeof(char*) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}

// 	return new;
// }

// int main(void)
// {
// 	t_point size = {8, 5};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};

// 	char**  area = make_area(zone, size);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	printf("\n");

// 	t_point	begin = {0, 1};
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	return (0);
// }
