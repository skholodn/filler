/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:26:19 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/01 19:41:11 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		strnew[i] = f(i, s[i]);
		i++;
	}
	return (strnew);
}
