/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:43:08 by skholodn          #+#    #+#             */
/*   Updated: 2016/11/28 19:03:00 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	tr_int;

	tr_int = n;
	if (tr_int < 0)
	{
		ft_putchar_fd('-', fd);
		tr_int = -tr_int;
	}
	if (tr_int >= 10)
	{
		ft_putnbr_fd(tr_int / 10, fd);
		ft_putnbr_fd(tr_int % 10, fd);
	}
	else
		ft_putchar_fd((tr_int + '0'), fd);
}
