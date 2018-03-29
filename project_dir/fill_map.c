/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:15:41 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/22 17:07:03 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	put_line(char *arr, int i, t_fill *fillst)
{
	int		a;

	a = -1;
	while (++a < fillst->x_size)
	{
		if (arr[a] == '.')
			fillst->map[i][a] = INT_MAX;
		else if (fillst->player == 'X')
		{
			if (arr[a] == 'o' || arr[a] == 'O')
				fillst->map[i][a] = 0;
			else if (arr[a] == 'X')
				fillst->map[i][a] = -1;
		}
		else if (fillst->player == 'O')
		{
			if (arr[a] == 'x' || arr[a] == 'X')
				fillst->map[i][a] = 0;
			else if (arr[a] == 'O')
				fillst->map[i][a] = -1;
		}
	}
}

void	check_fn(int x, int y, t_fill *fillst, int i)
{
	if (fillst->map[y][x] > i)
		fillst->map[y][x] = i;
}

void	for_line_enemy(int x, int y, t_fill *fillst, int i)
{
	if ((x + 1) < fillst->x_size)
	{
		check_fn(x + 1, y, fillst, i);
		if ((y + 1) < fillst->y_size)
			check_fn(x + 1, y + 1, fillst, i);
		if ((y - 1) >= 0)
			check_fn(x + 1, y - 1, fillst, i);
	}
	if ((x - 1) >= 0)
	{
		check_fn(x - 1, y, fillst, i);
		if ((y + 1) < fillst->y_size)
			check_fn(x - 1, y + 1, fillst, i);
		if ((y - 1) >= 0)
			check_fn(x - 1, y - 1, fillst, i);
	}
	if ((y + 1) < fillst->y_size)
		check_fn(x, y + 1, fillst, i);
	if ((y - 1) >= 0)
		check_fn(x, y - 1, fillst, i);
}

void	do_manhattan(t_fill *fillst, int i)
{
	int		x;
	int		y;
	int		nb;

	y = -1;
	nb = 0;
	while (++y < fillst->y_size)
	{
		x = -1;
		while (++x < fillst->x_size)
		{
			if (fillst->map[y][x] == i && nb++)
				for_line_enemy(x, y, fillst, i + 1);
		}
	}
	if (nb)
		do_manhattan(fillst, i + 1);
}

void	fill_map(char *line, t_fill *fillst)
{
	int		i;
	char	**arr;

	i = -1;
	while (++i < fillst->y_size)
	{
		get_next_line(0, &line);
		arr = ft_strsplit(line, ' ');
		put_line(arr[1], i, fillst);
		free_arr(arr);
	}
	do_manhattan(fillst, 0);
}
