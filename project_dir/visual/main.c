/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:26:56 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/22 16:18:43 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		my_key_funct(int key, t_map *map)
{
	if (key == 53)
		exit(0);
	if (key == 36 && map->stop)
	{
		write_game(map);
		return (1);
	}
	return (0);
}

void	init_map(t_map *map)
{
	read_output(map);
	read_output(map);
	map->flag = -1;
	map->stop = 1;
	map->winner = mlx_xpm_file_to_image(map->mlx,
		"winner.xpm", &map->w_width, &map->w_height);
}

int		main(void)
{
	t_map map;

	if (map.flag != -1)
		init_map(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WIN_NAME);
	mlx_string_put(map.mlx, map.win, 1150, 100, 0x00FF00, "PLAYER 1:");
	mlx_string_put(map.mlx, map.win, 1250, 100, 0x00FF00, map.name_1);
	mlx_string_put(map.mlx, map.win, 1150, 650, 0xFF0000, "PLAYER 2:");
	mlx_string_put(map.mlx, map.win, 1250, 650, 0xFF0000, map.name_2);
	if (map.stop)
		write_game(&map);
	mlx_hook(map.win, 2, 3, my_key_funct, &map);
	mlx_loop(map.mlx);
	return (0);
}
