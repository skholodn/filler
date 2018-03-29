/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:11:03 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/22 16:23:37 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	get_square_size(t_map *map)
{
	if (map->y_size == 15)
		map->size_square = MAP_00;
	else if (map->y_size == 24)
		map->size_square = MAP_01;
	else if (map->y_size == 100)
		map->size_square = MAP_02;
}

void	getmap(char *line, t_map *map)
{
	char	**arr;
	int		i;

	i = -1;
	arr = ft_strsplit(line, ' ');
	map->y_size = ft_atoi(arr[1]);
	map->x_size = ft_atoi(arr[2]);
	free_arr(arr);
	get_next_line(0, &line);
	map->map = (char **)ft_memalloc(sizeof(char*) * (map->y_size + 1));
	while (++i < map->y_size && get_next_line(0, &line))
	{
		arr = ft_strsplit(line, ' ');
		map->map[i] = ft_strdup(arr[1]);
		free_arr(arr);
	}
	get_square_size(map);
}

void	show_winner(char *line, t_map *map)
{
	map->score_1 = ft_atoi(line + 10);
	get_next_line(0, &line);
	map->score_2 = ft_atoi(line + 10);
	map->stop = 0;
}

void	read_output(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (!ft_strncmp("$$$ exec p1 : ", line, 14) && ++i)
			map->name_1 = ft_strdup(line + 14);
		else if (!ft_strncmp("$$$ exec p2 : ", line, 14) && ++i)
			map->name_2 = ft_strdup(line + 14);
		else if (!ft_strncmp("Plateau ", line, 8) && ++i)
			getmap(line, map);
		else if (!ft_strncmp("== O fin: ", line, 10) && ++i)
			show_winner(line, map);
		if (i)
			return ;
	}
}

void	put_pixel(t_map *map, int x, int y, char *color)
{
	int		cord;

	if (x < IMG_WIDTH && y < IMG_HEIGHT
			& x >= 0 && y >= 0)
	{
		cord = (int)((y * map->size_line) + (x * map->bpp / 8));
		map->data[cord] = color[2];
		map->data[cord + 1] = color[1];
		map->data[cord + 2] = color[0];
	}
}
