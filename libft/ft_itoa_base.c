/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 00:16:19 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/13 17:33:29 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int value, int base)
{
	int			len;
	long long	nbr;
	char		*str;
	char		*s_base;

	s_base = "0123456789abcdef";
	len = (int)ft_intsize(value, base);
	nbr = value;
	if (nbr < 0)
	{
		if (base == 10)
			len += 1;
		nbr *= -1;
	}
	str = ft_strnew(len);
	while (len > 0)
	{
		str[--len] = s_base[nbr % base];
		nbr /= base;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
