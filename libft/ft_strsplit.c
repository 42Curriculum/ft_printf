/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 09:51:09 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/18 18:26:10 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		norm_wont_get_me(int count, char **str, const char *s, int i)
{
	str[i++] = ft_strsub(s - count, 0, count);
	return (i);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		i;
	int		count;

	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(str = (char **)malloc((ft_ctwords((char *)s, c) + 1) * sizeof(*str))))
		return (NULL);
	while (*s)
	{
		count = 0;
		while (*s != c && *s)
		{
			s++;
			count++;
		}
		if (count > 0)
			i = norm_wont_get_me(count, str, s, i);
		while (*s == c && *s)
			s++;
	}
	str[i] = NULL;
	return (str);
}
