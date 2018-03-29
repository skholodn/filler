/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:22:47 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/01 18:40:23 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*strnew;
	int		len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!len)
		return (NULL);
	strnew = ft_strnew(len);
	if (!strnew)
		return (NULL);
	while (i < (size_t)len)
	{
		strnew[i] = f(s[i]);
		i++;
	}
	return (strnew);
}
