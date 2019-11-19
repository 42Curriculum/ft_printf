/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:37:09 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/01 10:32:33 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *arg, int i, size_t len)
{
	size_t			n;
	unsigned char	*car;

	car = (unsigned char *)arg;
	n = 0;
	while (n < len)
	{
		car[n] = i;
		n++;
	}
	return (arg);
}
