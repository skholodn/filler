/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:07:32 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/22 17:11:24 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <limits.h>

typedef struct	s_fill
{
	int			x_fig;
	int			y_fig;
	char		**piese;
	int			x_size;
	int			y_size;
	int			**map;
	char		player;
	int			set_y;
	int			set_x;
}				t_fill;

/*
** parsing name
*/

void			parse_name(char c, t_fill *fillst);

/*
** parsing map
*/

void			put_line(char *arr, int i, t_fill *fillst);
void			check_fn(int x, int y, t_fill *fillst, int i);
void			for_line_enemy(int x, int y, t_fill *fillst, int i);
void			do_manhattan(t_fill *fillst, int i);
void			fill_map(char *line, t_fill *fillst);

/*
** parsing token
*/

int				count_star(int x, int y, t_fill *fillst);
void			check_token(t_fill *fillst);
void			parse_token(char *line, t_fill *fillst);

/*
** CLEARING FUNCTIONS
*/

void			free_arr(char **arr);
void			free_int_arr(int **arr, int y);
void			null_fillst(t_fill *fillst);

#endif
