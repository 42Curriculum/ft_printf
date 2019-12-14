/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 07:48:49 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/13 16:44:41 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*norm_sucks(va_list *argp, int prec, int *sign, short fls)
{
	long double	arg;
	double		ar;
	char		*nb;

	if (FCL & fls)
	{
		arg = va_arg(*argp, long double);
		nb = get_ldouble(prec, arg, sign);
	}
	else
	{
		ar = va_arg(*argp, double);
		nb = get_double(prec, ar, sign);
	}
	return (nb);
}

void	conv_per(va_list *argp, short flags, int prec[])
{
	char	*p;
	int		size;

	(void)argp;
	size = 1;
	if (prec[0] > 1)
		(prec[0] = prec[0] - 1);
	else
		prec[0] = 0;
	size += prec[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p[0] = '%';
	((1 & flags)) ? fill_right(&p, prec[0]) : fill_left(&p, prec[0], flags);
	ft_putstr(p);
	free(p);
}

int		ft_printf(const char *str, ...)
{
	va_list argp;
	int		i;

	i = 0;
	va_start(argp, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == '%')
				write(1, "%", 1);
			else if (str[i] != '\0')
				i += read_chars((char *)(str + i), &argp, 0);
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(argp);
	return (1);
}
