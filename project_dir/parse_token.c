/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:16:45 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/22 17:17:11 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		count_star(int x, int y, t_fill *fillst)
{
	int		a;
	int		b;
	int		count;
	int		i;

	b = -1;
	count = 0;
	i = 0;
	while (++b < fillst->y_fig)
	{
		a = -1;
		while (++a < fillst->x_fig)
		{
			if (fillst->piese[b][a] == '*' && !fillst->map[b + y][a + x])
				return (INT_MAX);
			else if (fillst->piese[b][a] == '*' && fillst->map[b + y][a + x])
				count += fillst->map[b + y][a + x];
			if (fillst->piese[b][a] == '*' && fillst->map[b + y][a + x] == -1)
				i++;
		}
	}
	return ((i == 1) ? count : INT_MAX);
}

void	check_token(t_fill *fillst)
{
	int		a;
	int		b;
	int		count;

	b = -1;
	count = INT_MAX;
	while (++b <= fillst->y_size - fillst->y_fig)
	{
		a = -1;
		while (++a <= fillst->x_size - fillst->x_fig)
		{
			if (count > count_star(a, b, fillst))
			{
				count = count_star(a, b, fillst);
				fillst->set_x = a;
				fillst->set_y = b;
			}
		}
	}
	fillst->set_x = (count == INT_MAX) ? 0 : fillst->set_x;
	fillst->set_y = (count == INT_MAX) ? 0 : fillst->set_y;
}

void	parse_token(char *line, t_fill *fillst)
{
	char	**arr;
	int		i;

	i = -1;
	arr = ft_strsplit(line, ' ');
	fillst->y_fig = ft_atoi(arr[1]);
	fillst->x_fig = ft_atoi(arr[2]);
	free_arr(arr);
	fillst->piese = (char **)ft_memalloc(sizeof(char *) * (fillst->y_fig + 1));
	while (++i < fillst->y_fig)
		fillst->piese[i] = (char *)ft_memalloc(sizeof(char)
				* (fillst->x_fig + 1));
	i = -1;
	while (++i < fillst->y_fig && get_next_line(0, &line))
	{
		arr = ft_strsplit(line, ' ');
		ft_strcpy(fillst->piese[i], arr[0]);
		free_arr(arr);
	}
	check_token(fillst);
	ft_printf("%d %d\n", fillst->set_y, fillst->set_x);
}
