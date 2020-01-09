/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 07:48:49 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/08 17:46:47 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_width_prec(int i, int p_l, int (*wi_prec)[], char *c)
{
	((*wi_prec)[p_l] == -1) ? ((*wi_prec)[p_l] = 0) : (i += 0);
	(*wi_prec)[p_l] *= 10;
	(*wi_prec)[p_l] += *c - '0';
}

void	zeroprec_decimal(char *nb, short flags)
{
	int		i;
	char	*new;

	i = 0;
	while (nb[i] && nb[i] != '.')
		i++;
	if (flags & FHAS && (nb[i] != '.'))
	{
		new = malloc((int)ft_strlen(nb) + 1);
		new = ft_strncpy(new, nb, (int)ft_strlen(nb));
		new[(int)ft_strlen(nb)] = '.';
	}
	else
	{
		if (nb[i] == '.')
		{
			new = malloc(ft_strlen(nb) - 1);
			new = ft_strncpy(new, nb, ft_strlen(nb) - 1);
		}
		else
			new = ft_strdup(nb);
	}
	ft_putstr(new);
	free(new);
}

char	*which_double(va_list *argp, int prec, int *sign, short fls)
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

int		conv_per(va_list *argp, short fls, int prec[])
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
	((1 & fls)) ? fill_right(&p, prec[0], 0, fls) : fill_left(&p, prec[0], fls);
	ft_putstr(p);
	free(p);
	return (size);
}

int		ft_printf(const char *str, ...)
{
	va_list argp;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(argp, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == '%' && i++ && ++ret)
				write(1, "%", 1);
			else if (str[i] != '\0')
				i += read_chars((char *)(str + i), &argp, 0, &ret);
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			ret++;
		}
	}
	va_end(argp);
	return (ret);
}
