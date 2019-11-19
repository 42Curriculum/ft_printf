/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:03:29 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/19 19:18:53 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*nstr;
	unsigned char	*nstr2;

	nstr = (unsigned char *)str;
	nstr2 = (unsigned char *)str2;
	i = 0;
	while (n > 0 && nstr[i] == nstr2[i])
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	return (nstr[i] - nstr2[i]);
}
