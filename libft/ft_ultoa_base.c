/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:57:52 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/14 02:15:15 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/libft.h"
#include <limits.h>

unsigned int	ft_lintsize(unsigned long nb, unsigned long base)
{
	int len;

	len = 1;
	while (nb >= base)
	{
		nb /= base;
		len += 1;
	}
	return (len);
}

char			*ft_ultoa_base(unsigned long value, int base)
{
	int				len;
	unsigned long	nbr;
	char			*str;
	char			*s_base;

	s_base = "0123456789abcdef";
	len = (int)ft_lintsize(value, (unsigned long)base);
	nbr = value;
	str = ft_strnew(len);
	while (len > 0)
	{
		str[--len] = s_base[nbr % base];
		nbr /= base;
	}
	return (str);
}
