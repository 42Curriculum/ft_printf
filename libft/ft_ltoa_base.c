/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:24:14 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/14 01:19:56 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/libft.h"
#include <limits.h>

char		*ft_ltoa_base(long long value, int base)
{
	int			len;
	long long	nbr;
	char		*str;
	char		*s_base;

	s_base = "0123456789abcdef";
	if (value == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
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
