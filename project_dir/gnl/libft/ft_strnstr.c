/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:29:16 by skholodn          #+#    #+#             */
/*   Updated: 2016/11/29 16:22:35 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	a;
	size_t	b;
	int		test;

	a = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str[a] != '\0')
	{
		b = -1;
		test = 0;
		while (++b < ft_strlen(to_find))
			if (to_find[b] != str[a + b])
				test = -1;
		if (!test && a + b <= len)
			return ((char *)str + a);
		a++;
	}
	return (0);
}
