/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:02:49 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 15:26:19 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*list;
	unsigned char	*c_list;

	list = (t_list *)ft_memalloc(sizeof(t_list) + 1);
	if (list)
	{
		if (content)
		{
			c_list = (unsigned char *)ft_memalloc(content_size + 1);
			if (!c_list)
				return (NULL);
			ft_memmove(c_list, content, content_size);
			list->content = c_list;
			list->content_size = content_size;
		}
	}
	return (list);
}
