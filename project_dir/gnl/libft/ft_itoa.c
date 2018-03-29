/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:19:30 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 16:40:15 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	n_length(long l)
{
	int		i;

	i = 0;
	if (l < 0)
		l = l * (-1);
	if (l == 0)
		i = 1;
	while (l > 0)
	{
		l = l / 10;
		i++;
	}
	return (i);
}

static int	n_rate(int n_length)
{
	int		rate;

	rate = 1;
	while (n_length > 1)
	{
		rate = rate * 10;
		n_length--;
	}
	return (rate);
}

static char	*m_alocation(long l)
{
	char	*str;
	int		length;

	length = n_length(l);
	if (l < 0)
		str = (char *)malloc(sizeof(*str) * (length + 2));
	else
		str = (char *)malloc(sizeof(*str) * (length + 1));
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	l;
	int		i;
	int		length;

	i = 0;
	l = n;
	length = n_length(l);
	str = m_alocation(l);
	if (!str)
		return (0);
	if (l < 0)
	{
		str[i] = '-';
		l = l * (-1);
		i++;
	}
	while (length > 0)
	{
		str[i] = (l / n_rate(length--)) % 10 + '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
