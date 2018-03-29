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
	char	*str;
	size_t	l1;
	size_t	l2;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		i = -1;
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		str = (char *)ft_strnew((l1 + l2));
		if (str)
		{
			while (s1[++i])
				str[i] = s1[i];
			j = 0;
			while (s2[j])
				str[i++] = s2[j++];
			return (str);
		}
	}
	return (NULL);
}
