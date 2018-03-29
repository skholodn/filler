/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:29:11 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 22:00:30 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	a;
	size_t	b;
	int		test;
	char	*str_static;

	str_static = (char *)str;
	a = 0;
	if (ft_strlen(to_find) == 0)
		return (str_static);
	while (str[a])
	{
		b = -1;
		test = 0;
		while (++b < ft_strlen(to_find) && to_find[b])
			if (to_find[b] != str[a + b])
			{
				test = -1;
				break ;
			}
		if (!test)
			return (str_static + a);
		a++;
	}
	return (0);
}
