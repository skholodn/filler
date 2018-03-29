/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:42:28 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 15:27:25 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	if ((s = malloc(size)) == NULL)
		return (NULL);
	while (i < size)
		s[i++] = '\0';
	return (s);
}
