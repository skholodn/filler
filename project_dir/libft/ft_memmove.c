/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:48:10 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 18:25:38 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = len;
	if (len == 0 || dest == src)
		return (dest);
	if (dest > src)
	{
		while (l--)
		{
			((unsigned char *)dest)[l] = ((unsigned char *)src)[l];
		}
		return (dest);
	}
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
