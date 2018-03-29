/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:16:26 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/22 17:13:00 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parse_map(char *line, t_fill *fillst)
{
	char	**arr;
	int		i;

	i = -1;
	arr = ft_strsplit(line, ' ');
	fillst->y_size = ft_atoi(arr[1]);
	fillst->x_size = ft_atoi(arr[2]);
	free_arr(arr);
	get_next_line(0, &line);
	fillst->map = (int **)ft_memalloc(sizeof(int*) * fillst->y_size);
	while (++i < fillst->y_size)
		fillst->map[i] = (int *)ft_memalloc(sizeof(int) * fillst->x_size);
	fill_map(line, fillst);
}

int		main(void)
{
	char	*line;
	t_fill	fillst;

	while (get_next_line(0, &line))
	{
		if (!ft_strncmp("$$$ exec p", line, 10))
			parse_name(line[10], &fillst);
		if (!ft_strncmp(line, "Plateau ", 8))
			parse_map(line, &fillst);
		else if (!ft_strncmp(line, "Piece ", 6))
		{
			parse_token(line, &fillst);
			null_fillst(&fillst);
		}
	}
	return (0);
}
