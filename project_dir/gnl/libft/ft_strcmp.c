/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:58:59 by skholodn          #+#    #+#             */
/*   Updated: 2016/12/06 18:36:48 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	i = 0;
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	while (ts1[i] && ts2[i] && ts1[i] == ts2[i])
		i++;
	if (ts1[i] != ts2[i])
		return (ts1[i] - ts2[i]);
	return (0);
}
