/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:14:38 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 16:07:51 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strnew;

	strnew = NULL;
	if (s)
	{
		strnew = ft_strnew(len);
		if (!strnew)
			return (NULL);
		ft_strncpy(strnew, ((char *)s + start), len);
	}
	return (strnew);
}
