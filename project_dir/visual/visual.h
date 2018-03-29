/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:27:25 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/22 16:35:51 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <mlx.h>
# include "../filler.h"

typedef struct		s_map
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	void			*winner;
	int				w_width;
	int				w_height;
	int				size_square;
	char			*name_1;
	char			*name_2;
	char			**map;
	int				x_size;
	int				y_size;
	int				score_1;
	int				score_2;
	int				flag;
	int				stop;
}					t_map;

# define WINDOW_WIDTH 1800
# define WINDOW_HEIGHT 1200
# define WIN_NAME "Let the fight begin !)"

# define IMG_WIDTH 1100
# define IMG_HEIGHT 1200

# define MAP_00 60
# define MAP_01 26
# define MAP_02 10

void				get_square_size(t_map *map);
void				getmap(char *line, t_map *map);
void				show_winner(char *line, t_map *map);
void				read_output(t_map *map);
void				put_pixel(t_map *map, int x, int y, char *color);
void				write_table(t_map *map);
void				write_square(t_map *map, int x, int y, char *color);
void				set_map(t_map *map);
void				set_result(t_map *map);
void				write_game(t_map *map);

#endif
