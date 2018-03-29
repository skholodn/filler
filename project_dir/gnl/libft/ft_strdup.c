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
	int		lng;
	char	*copy;

	lng = 0;
	while (src[lng])
		lng++;
	copy = (char *)malloc(sizeof(char) * (lng + 1));
	if (!copy)
		return (0);
	ft_strcpy(copy, src);
	return (copy);
}
