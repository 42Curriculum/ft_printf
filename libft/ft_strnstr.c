/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:54:49 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/01 15:42:19 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (ft_strlen(find) == 0)
		return ((char *)str);
	while (str[i] && i < len)
	{
		n = 0;
		while (find[n] == str[i + n] && (i + n) < len)
		{
			if (find[n + 1] == '\0')
			{
				return ((char *)str + i);
			}
			n++;
		}
		i++;
	}
	return (NULL);
}
