/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:16:50 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 18:52:29 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	i = 0;
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (ts1[i] == ts2[i] && ts1[i] && ts2[i] && n > 1)
	{
		i++;
		n--;
	}
	return ((unsigned char)ts1[i] - (unsigned char)ts2[i]);
}
