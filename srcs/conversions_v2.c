/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:41:29 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/10 11:45:34 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_x(va_list *argp, short flags, int prec[])
{
	void	*arg;
	char	*nb;
	int		size;
	char	*p;

	arg = va_arg(*argp, void*);
	nb = hexcast(arg, flags, 16);
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
	if (FHAS & flags)
		ft_putstr("0x");
	ft_putstr(p);
	free(p);
}

void	conv_x_u(va_list *argp, short flags, int prec[])
{
	void	*arg;
	char	*nb;
	int		size;
	char	*p;

	arg = va_arg(*argp, void*);
	nb = hexcast(arg, flags, 16);
	nb = ft_str_toupper(nb);
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
	if (FHAS & flags)
		ft_putstr("0X");
	ft_putstr(p);
	free(p);
}

void	conv_f(va_list *argp, short fls, int prec[])
{
	int			sign;
	long long	size;
	char		*p;
	char		*nb;

	if (!(nb = norm_sucks(argp, prec[1], &sign, fls)))
		return ;
	size = ft_strlen(nb) + ((sign == 1 || fls & FPOS || fls & FSPA) ? 1 : 0);
	if (prec[0] > size)
		(prec[0] = prec[0] - size);
	else
		prec[0] = 0;
	size += prec[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p = ft_strncpy(p, nb, (int)ft_strlen(nb));
	((1 & fls)) ? fill_right(&p, prec[0]) : fill_left(&p, prec[0], fls);
	make_str(fls, sign, &p);
	ft_putstr(p);
	free(p);
}

void	conv_b(va_list *argp, short flags, int prec[])
{
	void	*arg;
	char	*nb;
	int		size;
	char	*p;

	arg = va_arg(*argp, void*);
	nb = hexcast(arg, flags, 2);
	nb = ft_str_toupper(nb);
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
	if (FHAS & flags)
		ft_putstr("0b");
	ft_putstr(p);
	free(p);
}

void	conv_u(va_list *argp, short flags, int prec[])
{
	void	*arg;
	char	*nb;
	int		size;
	char	*p;

	arg = va_arg(*argp, void*);
	nb = hexcast(arg, flags, 10);
	nb = ft_str_toupper(nb);
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
