/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:47:21 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/27 04:05:30 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s(va_list *argp, short flags, int prec)
{
	char *str;
	char *print;
	int size;
	int len;

	if (!(str = va_arg(*argp, char *)))
	{
		ft_putstr("(null)");
		return ;
	}
	size = ft_strlen(str);
	(prec - size) < 0 ? prec = 0 : (prec -= size);
	print = ft_strnew(len = (size + prec));
	if (flags != 0 || prec > 0)
		((0b00000001 & flags)) ? fill_right(&print, flags, len, str) : fill_left(&print, prec, flags, str);
	ft_putstr(print);
}

void	conv_c(va_list *argp, short flags, int prec)
{
	char c;
	char *print;
	
	int len;
	char *tmp;
	
	c = va_arg(*argp, int);
	(prec - 1) < 0 ? prec = 0 : (prec -= 1);
	print = ft_strnew(len = (prec + 1));
	print[0] = c;
	tmp = ft_strnew(1);
	tmp[0] = c;
	if (flags != 0 || prec > 0)
		((0b00000001 & flags)) ? fill_right(&print, flags, len, tmp) : fill_left(&print, prec, flags, tmp);
	ft_putstr(print);
}
