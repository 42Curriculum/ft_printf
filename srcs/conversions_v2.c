/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:41:29 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/08 17:52:05 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_x(va_list *argp, short fls, int pr[])
{
	void	*arg;
	char	*nb;
	int		size;
	char	*p;

	arg = va_arg(*argp, void *);
	nb = unsigned_cast(arg, fls, 16);
	if (FHAS & fls && !((ft_strlen(nb)) == 1 && nb[0] == '0'))
		nb = ft_better_strjoin(ft_strdup("0x"), nb);
	size = ft_strlen(nb);
	if (pr[0] > size)
		(pr[0] = pr[0] - size);
	else
		pr[0] = 0;
	size += pr[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p = ft_strncpy(p, nb, (int)ft_strlen(nb));
	((1 & fls)) ? fill_right(&p, pr[0], 0, fls) : fill_left(&p, pr[0], fls);
	ft_putstr(p);
	free(p);
	return (size);
}

int	conv_x_u(va_list *argp, short fls, int pr[])
{
	void	*arg;
	char	*nb;
	int		size;
	char	*p;

	arg = va_arg(*argp, void *);
	nb = unsigned_cast(arg, fls, 16);
	if (FHAS & fls && !((ft_strlen(nb)) == 1 && nb[0] == '0'))
		nb = ft_better_strjoin(ft_strdup("0x"), nb);
	ft_str_toupper(&nb);
	size = ft_strlen(nb);
	if (pr[0] > size)
		(pr[0] = pr[0] - size);
	else
		pr[0] = 0;
	size += pr[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p = ft_strncpy(p, nb, (int)ft_strlen(nb));
	((1 & fls)) ? fill_right(&p, pr[0], 0, fls) : fill_left(&p, pr[0], fls);
	ft_putstr(p);
	free(p);
	return (size);
}

int	conv_f(va_list *argp, short fls, int pr[])
{
	int			s;
	long long	size;
	char		*p;
	char		*nb;

	if (!(nb = which_double(argp, pr[1], &s, fls)))
		return (0);
	size = ft_strlen(nb);
	pr = 0;
	if ((fls & FSPA || fls & FPOS) && s == 0)
		size += 1;
	(pr[0] > size) ? (pr[0] = pr[0] - size) : (pr[0] += 0);
	size += pr[0];
	size += s;
	p = ft_strnew((size - ft_strlen(nb)));
	p = ft_memset(p, ' ', size - ft_strlen(nb));
	p = ft_better_strjoin(p, nb);
	if ((fls & FPOS || fls & FSPA) && s == 0)
		pr[0] += 1;
	(1 & fls) ? fill_right(&p, pr[0], s, fls) : fill_left(&p, pr[0] + s, fls);
	make_str(fls, s, &p);
	(pr[1] == 0) ? (zeroprec_decimal(p, fls)) : ft_putstr(p);
	free(p);
	return (size);
}

int	conv_b(va_list *argp, short fls, int pr[])
{
	void	*arg;
	char	*nb;
	int		size;
	char	*p;

	arg = va_arg(*argp, void *);
	nb = unsigned_cast(arg, fls, 2);
	if (FHAS & fls && !((ft_strlen(nb)) == 1 && nb[0] == '0'))
		nb = ft_better_strjoin(ft_strdup("0x"), nb);
	size = ft_strlen(nb);
	if (pr[0] > size)
		(pr[0] = pr[0] - size);
	else
		pr[0] = 0;
	size += pr[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p = ft_strncpy(p, nb, (int)ft_strlen(nb));
	((1 & fls)) ? fill_right(&p, pr[0], 0, fls) : fill_left(&p, pr[0], fls);
	ft_putstr(p);
	free(p);
	return (size);
}

int	conv_u(va_list *argp, short fls, int pr[])
{
	void	*arg;
	char	*nb;
	int		size;
	char	*p;

	arg = va_arg(*argp, void *);
	nb = unsigned_cast(arg, fls, 10);
	size = ft_strlen(nb);
	if (pr[0] > size)
		(pr[0] = pr[0] - size);
	else
		pr[0] = 0;
	size += pr[0];
	p = ft_strnew((size));
	p = ft_memset(p, ' ', size);
	p = ft_strncpy(p, nb, (int)ft_strlen(nb));
	((1 & fls)) ? fill_right(&p, pr[0], 0, fls) : fill_left(&p, pr[0], fls);
	ft_putstr(p);
	free(p);
	return (size);
}
