/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:11:39 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/22 16:29:19 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	write_table(t_map *map)
{
	int		x;
	int		y;
	char	color[3];

	color[0] = (char)255;
	color[1] = (char)255;
	color[2] = (char)255;
	y = -1;
	while (++y < map->y_size + 1)
	{
		x = -1;
		while (++x < map->x_size * map->size_square)
			put_pixel(map, x + map->size_square, (y + 1) *
					map->size_square, color);
	}
	x = -1;
	while (++x < map->x_size + 1)
	{
		y = -1;
		while (++y < map->y_size * map->size_square)
			put_pixel(map, (x + 1) * map->size_square, y
					+ map->size_square, color);
	}
}

void	write_square(t_map *map, int x, int y, char *color)
{
	int		a;
	int		b;

	b = -1;
	while (++b < map->size_square - 1)
	{
		a = -1;
		while (++a < map->size_square - 1)
		{
			put_pixel(map, (x + 1) * map->size_square + a + 1,
				(y + 1) * map->size_square + b + 1, color);
		}
	}
}

void	set_map(t_map *map)
{
	int		x;
	int		y;
	char	*color;

	y = -1;
	while (++y < map->y_size)
	{
		x = -1;
		while (++x < map->x_size)
		{
			color = ft_memalloc(sizeof(char) * 3);
			if (map->map[y][x] == 'O' && (color[1] = (char)255))
				write_square(map, x, y, color);
			else if (map->map[y][x] == 'X' && (color[0] = (char)255))
				write_square(map, x, y, color);
			else if ((map->map[y][x] == 'x' || map->map[y][x] == 'o')
				&& (color[0] = (char)255))
			{
				color[1] = (char)255;
				write_square(map, x, y, color);
			}
			free(color);
		}
	}
}

void	set_result(t_map *map)
{
	mlx_string_put(map->mlx, map->win, 1150, 120, 0x00FF00, "SCORE:");
	mlx_string_put(map->mlx, map->win, 1250, 120, 0x00FF00,
			ft_itoa(map->score_1));
	mlx_string_put(map->mlx, map->win, 1150, 670, 0xFF0000, "SCORE:");
	mlx_string_put(map->mlx, map->win, 1250, 670, 0xFF0000,
			ft_itoa(map->score_2));
	if (map->score_1 > map->score_2)
	{
		mlx_put_image_to_window(map->mlx, map->win,
				map->winner, 1250, 340);
	}
	else if (map->score_1 < map->score_2)
	{
		mlx_put_image_to_window(map->mlx, map->win,
				map->winner, 1250, 740);
	}
}

void	write_game(t_map *map)
{
	read_output(map);
	map->img = mlx_new_image(map->mlx, IMG_WIDTH, IMG_HEIGHT);
	map->data = mlx_get_data_addr(map->img, &(map->bpp),
			&(map->size_line), &(map->endian));
	write_table(map);
	set_map(map);
	if (!map->stop)
		set_result(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}
