/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 23:37:19 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/08 17:32:58 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*reallocate(char *str, int prec, int u_len)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (str[i] == '.')
		u_len++;
	new = ft_strnew(u_len - i + prec);
	if (str[i] == '.')
	{
		ft_strncpy(new + 1, str + i, u_len - i + prec - 1);
		new[0] = '0';
	}
	else
		new = ft_strncpy(new, str + i, u_len - i + prec - 1);
	return (new);
}

void	count_dec(char **str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '.')
		{
			count++;
			break ;
		}
		i++;
	}
	if (count == 0)
	{
		ft_str_shift(str, 2, '0');
		(*str)[0] = '1';
		(*str)[1] = '.';
	}
	else
		ft_str_add(str, 1, i);
}

char	*calc_precison(long long p, char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		i++;
	}
	i++;
	if (i == (int)ft_strlen(str))
		return (reallocate(str, p, 0));
	if (p == -1)
		p = 6;
	if (str[i + p] >= '5')
		(p == 0) ? ft_str_add(&str, 1, i + p - 1) : ft_str_add(&str, 1, i + p);
	new = reallocate(str, p, i);
	return (new);
}

char	*calc_number(char *str, int exp, int skip)
{
	long long i;

	i = 0;
	while (i < 52 && skip == 0)
	{
		ft_strdiv(&str, 2, 0);
		i++;
	}
	count_dec(&str);
	i = 0;
	while (i < exp)
	{
		ft_strmult(&str, 2, ft_strlen(str));
		i++;
	}
	while (i > exp)
	{
		ft_strdiv(&str, 2, 0);
		i--;
	}
	return (str);
}

char	*get_double(int precision, double arg, int *sign)
{
	union u_dval	u_dval;
	long long		mantissa;
	char			*tmp;
	int				exp;
	char			*str;

	u_dval.type = (double)arg;
	exp = u_dval.bits.exp - 1023;
	mantissa = u_dval.bits.mantissa;
	*sign = u_dval.bits.sign;
	str = ft_strnew(1023);
	ft_memset(str, '-', 1023);
	tmp = ft_ltoa_base(mantissa, 10);
	str = ft_memmove(str, tmp, ft_strlen(tmp));
	if (mantissa != 0)
		str = calc_number(str, exp, 0);
	else
		str = calc_number(str, exp, 1);
	str = calc_precison(precision, str);
	return (str);
}
