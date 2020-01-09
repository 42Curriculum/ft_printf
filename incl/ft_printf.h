/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 07:58:23 by jjosephi          #+#    #+#             */
/*   Updated: 2020/01/08 17:47:07 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/incl/libft.h"

# define FNEG 0x1
# define FPOS 0x2
# define FSPA 0x4
# define FLON 0x8
# define FLLO 0x10
# define FH 0x20
# define FHH 0x40
# define FCL 0x80
# define FHAS 0x100
# define F0FI 0x200
# define FSTA 0x400
# define FPRE 0x800
# define D_BIAS 1023
# define LD_BIAS 16383
# define BIT_EXC 0x4000000000000000

union					u_dval
{
	double				type;
	struct
	{
		unsigned long	mantissa	: 52;
		unsigned int	exp			: 11;
		unsigned int	sign		: 1;
	}					bits;
}						u_dval;

union					u_ldval
{
	long double			type;
	struct
	{
		unsigned long	mantissa	: 63;
		int				magoc		: 1;
		unsigned int	exp			: 15;
		unsigned int	sign		: 1;
	}					bits;
}						u_ldval;

typedef int			t_func(va_list *argp, short flags, int precision[]);

void					set_width_prec(int i, int p_l, int (*wi_prec)[], char *c);
void					zeroprec_decimal(char *nb, short flags);
int						conv_per(va_list *argp, short flags, int prec[]);
char					*which_double(va_list *a, int pr, int *si, short fls);
int						ft_printf(const char *str, ...);

int						read_chars(char *str, va_list *argp, int num, int *ret);

int						conv_s(va_list *argp, short flags, int prec[]);
int						conv_c(va_list *argp, short flags, int prec[]);
int						conv_p(va_list *argp, short flags, int prec[]);
int						conv_d(va_list *argp, short flags, int prec[]);
int						conv_o(va_list *argp, short flags, int prec[]);

int						conv_x(va_list *argp, short flags, int prec[]);
int						conv_f(va_list *argp, short flags, int prec[]);
int						conv_b(va_list *argp, short flags, int prec[]);
int						conv_u(va_list *argp, short flags, int prec[]);
int						conv_x_u(va_list *argp, short flags, int prec[]);

char					*get_double(int precision, double arg, int *sign);
char					*get_ldouble(int precision, long double arg, int *sign);

void					fill_left(char **str, int precision, short flags);
void	                fill_right(char **str, int size, int sign, short flag);
void					make_str(short flags, int sign, char **nb);
char					*signed_cast(va_list *argp, short flags, int base);

char					*unsigned_cast(void *arg, short flags, int base);

#endif
