/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:34:55 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/19 14:23:31 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t len;
	size_t i;
	size_t destl;

	destl = ft_strlen(dst);
	i = 0;
	len = destl;
	if (destsize <= 0)
		return (ft_strlen(src));
	while (src[i] && destl < destsize - 1)
	{
		dst[destl] = src[i];
		i++;
		destl++;
	}
	dst[destl] = '\0';
	if (destsize < len)
		return (destsize + ft_strlen(src));
	return (len + ft_strlen(src));
}
