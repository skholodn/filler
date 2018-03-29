/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:12:35 by skholodn          #+#    #+#             */
/*   Updated: 2016/11/29 13:17:57 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;
	size_t	s;

	i = 0;
	j = 0;
	s = size;
	while (dest[i] != '\0' && s-- != 0)
		i++;
	l = i;
	s = size - l;
	if (s == 0)
		return (l + ft_strlen(src));
	while (j != (size - l - 1))
	{
		if (s-- != 1)
			dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (l + ft_strlen(src));
}
