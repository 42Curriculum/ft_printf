/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:07:52 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/27 03:15:51 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

func	*define_func(int conv)
{
	func *f_arr[2] = {&conv_s, &conv_c};
	return(f_arr[conv]);
}

void	define_flags(int (*flags)[12])
{
	(*flags)[0] = 45;
	(*flags)[1] = 43;
	(*flags)[2] = 32;
	(*flags)[3] = 108;
	(*flags)[4] = 216;
	(*flags)[5] = 104;
	(*flags)[6] = 208;
	(*flags)[7] = 76;
	(*flags)[8] = 35;
	(*flags)[9] = 48;
	(*flags)[10] = 42;
	(*flags)[11] = 46;
}

int		get_conversion(char c)
{
	char fs[3];
	int i;
	
	fs[0] = 's';
	fs[1] = 'c';
	fs[2] = 'p';
	i = 0;
	while(i < 3)
	{
		if (c == fs[i])
			return (i);
		i++;
	}
	return (-1);
}

void	get_flags(char *c, short *flags, int *precision)
{
	short mask;
	int flags_ar[12];
	int i;
	int test;
	
	i = 0;
	mask = 0b0000000000000001;
	test = *(c - 1);
	define_flags(&flags_ar);
	while (i < 13)
	{
		if ((int)*c == flags_ar[i])
		{
			if (((int)(*(c + 1)) + (int)*c) == flags_ar[i++])
				mask = mask << 1;
			*flags |= mask;
			break ;
		}
		else if ((*c > '0' && *c <= '9') || ((*c == '0') && ft_isdigit(*(c - 1))))
		{
			*precision *= 10;
			*precision += *c - '0';
			break ;
		}
		mask = mask << 1;
		i++;
	}
}

int		read_chars(char *str, va_list *argp)
{
	func *function;
	short flags;
	int i;
	int conv;
	int precision;
	
	i = 0;
	precision = 0;
	while ((conv = get_conversion(str[i])) == -1)
	{
		get_flags(&str[i], &flags, &precision);
		i++;
	}
	i++;
	function = define_func(conv);
	if (precision == 0 && (0b0000010000000000 & flags))
		precision = va_arg(*argp, int);
	function(argp, flags, precision);
	return (i);
} 