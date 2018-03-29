/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:39:26 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 16:08:58 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_delim(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*strnew;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (ft_delim(s[len - 1]))
		len--;
	i = -1;
	while (ft_delim(s[++i]))
		len--;
	if (len < 0)
		len = 0;
	strnew = ft_strsub(s, i, len);
	return (strnew);
}
