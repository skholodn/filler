/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:18:16 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/05 20:17:07 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = 0;
	if (!lst || !(f))
		return (NULL);
	if (lst)
	{
		if (f(lst))
		{
			new = ft_lstnew((f(lst))->content, (f(lst))->content_size);
			lst = lst->next;
			new->next = ft_lstmap(lst, f);
		}
		else
			lst = lst->next;
	}
	else
		new->next = NULL;
	return (new);
}
