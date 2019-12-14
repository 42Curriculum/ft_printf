/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 01:36:09 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/14 01:37:46 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/libft.h"

char		*ft_uitoa_base(unsigned int value, int base)
{
	int				len;
	unsigned long	nbr;
	char			*str;
	char			*s_base;

	s_base = "0123456789abcdef";
	len = (int)ft_intsize(value, base);
	nbr = value;
	str = ft_strnew(len);
	while (len > 0)
	{
		str[--len] = s_base[nbr % base];
		nbr /= base;
	}
	return (str);
}
