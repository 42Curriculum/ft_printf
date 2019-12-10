/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:41:46 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/09 21:45:17 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

void	fill_left(char **str, int precision, short flags)
{
	int i;

	i = 0;
	ft_str_shift(str, precision, '\0');
	while (i < precision)
	{
		if (0b0000001000000000 & flags)
			(*str)[i] = '0';
		else
			(*str)[i] = ' ';
		i++;
	}
}

void	fill_right(char **str, int size)
{
	int i;

	i = ft_strlen(*str);
	while (i < size)
	{
		(*str)[i] = ' ';
		i++;
	}
}

void	make_str(short flags, int sign, char **nb)
{
	if (sign == 1 || flags & FSPA || flags & FPOS)
	{
		ft_str_shift(nb, 1, '\0');
		if (sign == 1)
			(*nb)[0] = '-';
		else if (flags & FSPA)
			(*nb)[0] = ' ';
		else
			(*nb)[0] = '+';
	}
}

char	*typecast(va_list *argp, short flags, int base)
{
	char *str;

	if (flags & 0b0000000000001000)
		str = ft_ltoa_base(va_arg(*argp, long), base);
	else if (flags & 0b0000000000010000)
		str = ft_ltoa_base(va_arg(*argp, long long), base);
	else if (flags & 0b0000000000100000)
		str = ft_itoa_base((short)(va_arg(*argp, int)), base);
	else if (flags & 0b0000000001000000)
		str = ft_itoa_base((signed char)(va_arg(*argp, int)), base);
	else
		str = ft_itoa_base((int)(va_arg(*argp, int)), base);
	return (str);
}

char	*hexcast(void *arg, short flags, int base)
{
	char *str;

	if (flags & 0b0000000000001000)
		str = ft_itoa_base((unsigned long)arg, base);
	else if (flags & 0b0000000000010000)
		str = ft_itoa_base((unsigned long long)arg, base);
	else if (flags & 0b0000000000100000)
		str = ft_itoa_base((unsigned short)arg, base);
	else if (flags & 0b0000000001000000)
		str = ft_itoa_base((signed char)arg, base);
	else
		str = ft_itoa_base((unsigned int)arg, base);
	return (str);
}
