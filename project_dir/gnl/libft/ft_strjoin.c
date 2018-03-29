/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:50:21 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/01 21:37:23 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	size_t	i;
	size_t	j;
	char	*strnew;

	if (s1 && s2)
	{
		i = -1;
		ls1 = ft_strlen(s1);
		ls2 = ft_strlen(s2);
		strnew = ft_strnew(ls1 + ls2);
		if (!strnew)
			return (NULL);
		while (s1[++i])
			strnew[i] = s1[i];
		j = 0;
		while (s2[j])
			strnew[i++] = s2[j++];
		return (strnew);
	}
	return (NULL);
}
