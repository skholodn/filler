/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:07:53 by skholodn          #+#    #+#             */
/*   Updated: 2016/11/28 19:02:45 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	long	tr_int;

	tr_int = n;
	if (tr_int < 0)
	{
		ft_putchar('-');
		tr_int = -tr_int;
	}
	if (tr_int >= 10)
	{
		ft_putnbr(tr_int / 10);
		ft_putnbr(tr_int % 10);
	}
	else
		ft_putchar(tr_int + '0');
}
