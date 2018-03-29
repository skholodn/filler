/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:15:20 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/22 16:59:30 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_arr(char **arr)
{
	int		a;

	a = 0;
	while (arr[a])
	{
		free(arr[a]);
		a++;
	}
	free(arr);
}

void	free_int_arr(int **arr, int y)
{
	int		a;

	a = 0;
	while (a < y)
	{
		free(arr[a]);
		a++;
	}
	free(arr);
}

void	null_fillst(t_fill *fillst)
{
	fillst->x_fig = 0;
	fillst->y_fig = 0;
	free_arr(fillst->piese);
	free_int_arr(fillst->map, fillst->y_size);
	fillst->x_size = 0;
	fillst->y_size = 0;
	fillst->set_y = 0;
	fillst->set_x = 0;
}
