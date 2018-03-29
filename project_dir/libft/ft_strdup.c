/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:45:46 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/01 10:59:07 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*cp_str;
	size_t	len;
	int		i;

	i = -1;
	len = ft_strlen(src);
	cp_str = (char *)malloc(len + 1);
	if (!cp_str)
		return (NULL);
	while (src[++i] != '\0')
		cp_str[i] = src[i];
	cp_str[i] = '\0';
	return (cp_str);
}
