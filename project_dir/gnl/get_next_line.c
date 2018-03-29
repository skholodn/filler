/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:08:58 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/19 20:16:37 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_newlst(int const fd)
{
	t_list		*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->content = ft_strnew(BUFF_SIZE + 1);
	lst->content_size = (size_t)fd;
	lst->next = 0;
	return (lst);
}

static char		*ft_get_buf(int const fd)
{
	static t_list	*s_temp = 0;
	t_list			*lst;

	lst = s_temp;
	if (!s_temp)
	{
		s_temp = ft_newlst(fd);
		return (s_temp->content);
	}
	while (lst)
	{
		if (lst->content_size == (size_t)fd)
			return (lst->content);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	lst->next = ft_newlst(fd);
	return (lst->next->content);
}

static int		get_info_from_buffer(char *buf, char **line)
{
	char	*nl_place;
	char	*cpy_holder;
	char	*holder;

	nl_place = ft_strchr(buf, '\n');
	holder = *line;
	if (nl_place)
	{
		cpy_holder = ft_strnew(nl_place - buf);
		*line = ft_strjoin(*line, ft_strncpy(cpy_holder, buf,
					(nl_place - buf)));
		ft_strcpy(buf, nl_place + 1);
		free(holder);
		free(cpy_holder);
		return (1);
	}
	*line = ft_strjoin(*line, buf);
	ft_strclr(buf);
	free(holder);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	char	*buf;
	char	*rd_str;
	size_t	r;

	buf = ft_get_buf(fd);
	if (read(fd, buf, 0) == -1 || fd < 0 || !line)
		return (-1);
	rd_str = ft_strnew(0);
	while (1)
	{
		if (get_info_from_buffer(buf, &rd_str))
			break ;
		else if ((r = read(fd, buf, BUFF_SIZE)) == 0)
		{
			if (!*rd_str)
				return (0);
			else
				break ;
		}
		buf[r] = '\0';
	}
	*line = rd_str;
	return (1);
}
