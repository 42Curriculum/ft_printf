/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:07:52 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/08 17:47:40 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_func	*define_func(int conv)
{
	t_func *f_arr[12];

	f_arr[0] = &conv_s;
	f_arr[1] = &conv_c;
	f_arr[2] = &conv_p;
	f_arr[3] = &conv_d;
	f_arr[4] = &conv_d;
	f_arr[5] = &conv_o;
	f_arr[6] = &conv_x;
	f_arr[7] = &conv_x_u;
	f_arr[8] = &conv_f;
	f_arr[9] = &conv_b;
	f_arr[10] = &conv_u;
	f_arr[11] = &conv_per;
	return (f_arr[conv]);
}

void	define_flags(char (*flags)[12], int *pl)
{
	*pl = 0;
	(*flags)[0] = '-';
	(*flags)[1] = '+';
	(*flags)[2] = ' ';
	(*flags)[3] = 'l';
	(*flags)[4] = '\0';
	(*flags)[5] = 'h';
	(*flags)[6] = '\0';
	(*flags)[7] = 'L';
	(*flags)[8] = '#';
	(*flags)[9] = '0';
	(*flags)[10] = '*';
	(*flags)[11] = '.';
}

int		get_conversion(char c)
{
	char	fs[12];
	int		i;

	fs[0] = 's';
	fs[1] = 'c';
	fs[2] = 'p';
	fs[3] = 'i';
	fs[4] = 'd';
	fs[5] = 'o';
	fs[6] = 'x';
	fs[7] = 'X';
	fs[8] = 'f';
	fs[9] = 'b';
	fs[10] = 'u';
	fs[11] = '%';
	i = 0;
	while (i < 12)
	{
		if (c == fs[i])
			return (i);
		i++;
	}
	return (-1);
}

void	get_flags(char *c, short *flags, int (*wi_prec)[2], int i)
{
	short	mask;
	char	flags_ar[12];
	int		p_l;

	mask = 0b0000000000000001;
	define_flags(&flags_ar, &p_l);
	(*flags & 0b0000100000000000) ? (p_l += 1) : (p_l = 0);
	while (++i < 13)
	{
		if ((*c > '0' && *c <= '9') || ((*c == '0') &&
		(ft_isdigit(*(c - 1)) || p_l == 1)))
		{
			set_width_prec(i, p_l, wi_prec, c);
			return ;
		}
		else if (*c == flags_ar[i])
		{
			if (*c != '0' && (0b0000000001111000 & *flags) > 0)
				return ;
			if ((*c == 'h' || *c == 'l') && (*(c + 1)) == *c)
				mask = mask << 1;
			*flags |= mask;
		}
		mask = mask << 1;
	}
}

int		read_chars(char *str, va_list *argp, int num, int *ret)
{
	t_func	*function;
	short	flags;
	int		i;
	int		conv;
	int		wi_prec[2];

	i = 0;
	wi_prec[0] = 0;
	wi_prec[1] = -1;
	flags = 0;
	while (str[i] && (conv = get_conversion(str[i])) == -1)
	{
		if (str[i] == '*' && !(flags & 0b0000010000000000))
		{
			wi_prec[num] = va_arg(*argp, int);
			num++;
		}
		else
			get_flags(&str[i], &flags, &wi_prec, -1);
		i++;
	}
	if (conv <= 11 && conv >= 0 && (function = define_func(conv)))
		*ret += function(argp, flags, wi_prec);
	return (i + 1);
}
