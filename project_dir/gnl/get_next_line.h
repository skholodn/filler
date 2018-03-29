/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:09:26 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/17 18:11:27 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 110

int		get_next_line(int const fd, char **line);

#endif
