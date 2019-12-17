/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:47:21 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/17 00:20:24 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s(va_list *argp, short flags, int prec[])
{
	char	*str;
	char	*p;
	int		size;

	if (!(str = va_arg(*argp, char *)))
	{
		ft_putstr("(null)");
		return ;
	}
	size = ft_strlen(str);
	if (prec[0] > size)
		(prec[0] = prec[0] - size);
	else
		prec[0] = 0;
	size += prec[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p = ft_strncpy(p, str, (int)ft_strlen(str));
	(1 & flags) ? fill_right(&p, prec[0]) : fill_left(&p, prec[0], flags);
	ft_putstr(p);
	free(p);
}

void	conv_c(va_list *argp, short flags, int prec[])
{
	char	c;
	char	*p;
	int		size;

	c = va_arg(*argp, int);
	size = 1;
	if (prec[0] > 1)
		(prec[0] = prec[0] - 1);
	else
		prec[0] = 0;
	size += prec[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p[0] = c;
	((1 & flags)) ? fill_right(&p, prec[0]) : fill_left(&p, prec[0], flags);
	ft_putstr(p);
	free(p);
}

void	conv_p(va_list *argp, short flags, int prec[])
{
	void	*ptr;
	char	*address;
	char	*p;
	int		size;

	ptr = va_arg(*argp, void*);
	address = ft_ultoa_base((unsigned long)(ptr), 16);
	size = ft_strlen(address) + 2;
	if (prec[0] > size)
		(prec[0] = prec[0] - size);
	else
		prec[0] = 0;
	size += prec[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p = ft_strncpy(p, address, (int)ft_strlen(address));
	(1 & flags) ? fill_right(&p, prec[0]) : fill_left(&p, prec[0], flags);
	ft_putstr("0x");
	ft_putstr(p);
	free(p);
	free(address);
}

void	conv_d(va_list *argp, short flags, int prec[])
{
	char	*nb;
	int		size;
	char	*p;
    int     sign;

	nb = typecast(argp, flags, 10);
    (nb[0] == '-') ? (sign = 1) : (sign = 0);
	size = ft_strlen(nb);
    if (flags & FSPA || flags & FPOS)
        size += 1;
	if (prec[0] > size)
		(prec[0] = prec[0] - size);
	else
		prec[0] = 0;
	size += prec[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p = ft_strncpy(p, nb, (int)ft_strlen(nb));
	(1 & flags) ? fill_right(&p, prec[0]) : fill_left(&p, prec[0], flags);
    make_str(flags, sign, &p);
	ft_putstr(p);
	free(p);
	free(nb);
}

void	conv_o(va_list *argp, short flags, int prec[])
{
	void	*arg;
	char	*nb;
	int		size;
	char	*p;

	arg = va_arg(*argp, void*);
	nb = hexcast(arg, flags, 8);
	if (FHAS & flags && !((ft_strlen(nb)) == 1 && nb[0] == '0'))
		nb = ft_better_strjoin(ft_strdup("0"), nb);
	size = ft_strlen(nb);
	if (prec[0] > size)
		(prec[0] = prec[0] - size);
	else
		prec[0] = 0;
	size += prec[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p = ft_strncpy(p, nb, (int)ft_strlen(nb));
	((1 & flags)) ? fill_right(&p, prec[0]) : fill_left(&p, prec[0], flags);
	ft_putstr(p);
	free(p);
}
