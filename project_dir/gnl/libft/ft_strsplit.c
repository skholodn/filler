/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:53:02 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 20:31:18 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	wrd_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c && i >= 1)
			count++;
	}
	return (count);
}

static void	ft_magic(char **strarr, char *strar, char const *s, char c)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	while (s[i])
	{
		j = 0;
		while (*(s + i) == c && *(s + i))
			i++;
		while (*(s + i) != c && *(s + i))
			*(strar + j++) = *(s + i++);
		if (x < wrd_count(s, c) - 1 && s[i])
			strar = *(strarr + ++x);
	}
	if (i)
		(s[i - 1] == c && i && !j) ? ((*(strarr + x) = NULL))
		: ((*(strarr + ++x) = NULL));
	else
		*(strarr + x) = NULL;
}

static void	ft_arr_create(char **strarr, const char *s, char c)
{
	int		i;
	int		j;
	int		char_count;

	i = 0;
	j = 0;
	while (*(s + i))
	{
		char_count = 0;
		while (*(s + i) == c && *(s + i))
			i++;
		while (*(s + i) != c && *(s + i))
		{
			i++;
			char_count++;
		}
		*(strarr + j) = ft_strnew(char_count);
		if (!*(strarr + j++))
			break ;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**strarr;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	strarr = (char **)malloc(sizeof(char *) * (wrd_count(s, c)));
	if (!strarr)
		return (NULL);
	ft_arr_create(strarr, s, c);
	while (j < wrd_count(s, c) - 1)
	{
		if (!*(strarr + j++))
		{
			ft_arrdel(strarr);
			return (NULL);
		}
	}
	ft_magic(strarr, *strarr, s, c);
	return (strarr);
}
