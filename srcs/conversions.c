/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:47:21 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/08 17:50:06 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_s(va_list *argp, short flags, int pr[])
{
	char	*str;
	char	*p;
	int		size;

	if (!(str = va_arg(*argp, char *)))
	{
		ft_putstr("(null)");
		return (6);
	}
	size = 0;
	(pr[1] == -1) ? (size += ft_strlen(str)) : (size = pr[1]);
	if (pr[0] > size)
		(pr[0] = pr[0] - size);
	else
		pr[0] = 0;
	size += pr[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	ft_strncpy(p + pr[0], str, (pr[1] == -1) ? (ft_strlen(str)) : (pr[1]));
	(1 & flags) ? fill_right(&p, pr[0], 0, flags) : fill_left(&p, pr[0], flags);
	ft_putstr(p);
	free(p);
	return (size);
}

int	conv_c(va_list *argp, short fls, int prec[])
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
	((1 & fls)) ? fill_right(&p, prec[0], 0, fls) : fill_left(&p, prec[0], fls);
	ft_putstr(p);
	free(p);
	return (size);
}

int	conv_p(va_list *argp, short flags, int prec[])
{
	void	*ptr;
	char	*address;
	char	*p;
	int		size;

	ptr = va_arg(*argp, void *);
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
	(1 & flags) ? fill_right(&p, prec[0], 0, 0) : fill_left(&p, prec[0], flags);
	ft_putstr("0x");
	ft_putstr(p);
	free(p);
	free(address);
	return (size);
}

int	conv_d(va_list *argp, short fs, int pr[])
{
	char	*nb;
	int		size;
	char	*p;
	int		s;

	s = 0;
	pr = 0;
	nb = signed_cast(argp, fs, 10);
	(nb[0] == '-') ? (s = 1) : (s += 0);
	(nb[0] == '-') ? (nb[0] = ' ') : (nb[0] += 0);
	size = ft_strlen(nb);
	if ((fs & FSPA || fs & FPOS) && s == 0)
		size += 1;
	(pr[0] > size) ? (pr[0] = pr[0] - size) : (pr[0] += 0);
	size += pr[0];
	p = ft_strnew((size - ft_strlen(nb)));
	p = ft_memset(p, ' ', size - ft_strlen(nb));
	p = ft_better_strjoin(p, nb);
	if ((fs & FPOS || fs & FSPA) && s == 0)
		pr[0] += 1;
	(1 & fs) ? fill_right(&p, pr[0], s, fs) : fill_left(&p, pr[0] + s, fs);
	make_str(fs, s, &p);
	ft_putstr(p);
	free(p);
	return (size);
}

int	conv_o(va_list *argp, short fls, int prec[])
{
	void	*arg;
	char	*nb;
	int		size;
	char	*p;

	arg = va_arg(*argp, void *);
	nb = unsigned_cast(arg, fls, 8);
	if (FHAS & fls && !((ft_strlen(nb)) == 1 && nb[0] == '0'))
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
	((1 & fls)) ? fill_right(&p, prec[0], 0, fls) : fill_left(&p, prec[0], fls);
	ft_putstr(p);
	free(p);
	return (size);
}
