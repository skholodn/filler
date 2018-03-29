/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:09:33 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 19:06:25 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;
	char	*psl;

	psl = 0;
	ps = (char *)s;
	while (*ps)
		if (*ps++ == (char)c)
			psl = ps - 1;
	if (c == '\0')
		return (ps);
	if (psl != 0)
		return (psl);
	return (NULL);
}
