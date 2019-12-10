/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 07:48:49 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/09 21:27:01 by jjosephi         ###   ########.fr       */
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
			if (str[i + 1] == '%')
				write(1, "%", 1);
			else
			{
				i += read_chars((char *)(str + i), &argp, 0);
			}
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
