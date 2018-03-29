/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:44:29 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 15:28:32 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*destp;
	unsigned char	*srcp;
	size_t			i;

	destp = dest;
	srcp = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		if ((*destp++ = *srcp++) == (unsigned char)c)
			return (destp);
	return (NULL);
}
