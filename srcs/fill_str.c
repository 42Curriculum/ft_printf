/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:41:46 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/07 23:06:07 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

void	fill_left(char **str, int precision, short flags)
{
	int i;

	i = 0;
	while (i < precision)
	{
		if (F0FI & flags)
			(*str)[i] = '0';
		else
			(*str)[i] = ' ';
		i++;
	}

}

void	fill_right(char **str, int size, int sign, short flag)
{
	int i;
    int shift;
    char *tmp;

	i = ft_strlen(*str);
    if ((flag & FPOS || flag & FSPA) && sign == 0)
        shift = (size -= 1) + 1;
    else if (sign == 1)
        shift = size - 1 + sign + 1;
    else
        shift = size -= 1;
    tmp = ft_strdup((*str));
    if (size > 0)
    {
        while (i-- && --shift >= 0)
        {
            (*str)[shift] = tmp[i];
        }
        i = ft_strlen(*str) - 1;
	    while (i > size)
	    {
		    (*str)[i] = ' ';
		    i--;
	    }
    }
}

void	make_str(short flags, int sign, char **nb)
{
    int i;

    i = 0;
	if (sign == 1 || flags & FSPA || flags & FPOS)
	{
		if (sign == 1)
        {
           /*  while ((*nb)[i] == ' ')
                i++;
			(i > 0) ? ((*nb)[i - 1] = '-') : ((*nb)[i] = '-'); */
			nb[0] = '-';
        }
		else if (flags & FPOS)
			(*nb)[0] = '+';
		else
			(*nb)[0] = ' ';
	}
}

char	*signed_cast(va_list *argp, short flags, int base)
{
	char *str;

	if (flags & FLON)
		str = ft_ltoa_base(va_arg(*argp, long), base);
	else if (flags & FLLO)
		str = ft_ltoa_base(va_arg(*argp, long long), base);
	else if (flags & FH)
		str = ft_itoa_base((short)(va_arg(*argp, int)), base);
	else if (flags & FHH)
		str = ft_itoa_base((signed char)(va_arg(*argp, int)), base);
	else
		str = ft_itoa_base((int)(va_arg(*argp, int)), base);
	return (str);
}

char	*unsigned_cast(void *arg, short flags, int base)
{
	char *str;

	if (flags & FLON)
		str = ft_ultoa_base((unsigned long)arg, base);
	else if (flags & FLLO)
		str = ft_ultoa_base((unsigned long long)arg, base);
	else if (flags & FH)
		str = ft_uitoa_base((unsigned short)arg, base);
	else if (flags & FHH)
		str = ft_uitoa_base((signed char)arg, base);
	else
		str = ft_uitoa_base((unsigned int)arg, base);
	return (str);
}
