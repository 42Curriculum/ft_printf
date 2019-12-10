/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 07:58:23 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/10 11:50:03 by jjosephi         ###   ########.fr       */
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

typedef void			t_func(va_list *argp, short flags, int precision[]);

int						f_exceptions(long long mantissa, int exp, int sign);
char					*norm_sucks(va_list *a, int pr, int *si, short fls);
int						ft_printf(const char *str, ...);

int						read_chars(char *str, va_list *argp, int num);

void					conv_s(va_list *argp, short flags, int prec[]);
void					conv_c(va_list *argp, short flags, int prec[]);
void					conv_p(va_list *argp, short flags, int prec[]);
void					conv_d(va_list *argp, short flags, int prec[]);
void					conv_o(va_list *argp, short flags, int prec[]);

void					conv_x(va_list *argp, short flags, int prec[]);
void					conv_f(va_list *argp, short flags, int prec[]);
void					conv_b(va_list *argp, short flags, int prec[]);
void					conv_u(va_list *argp, short flags, int prec[]);
void					conv_x_u(va_list *argp, short flags, int prec[]);

char					*get_double(int precision, double arg, int *sign);
char					*get_ldouble(int precision, long double arg, int *sign);

void					fill_left(char **str, int precision, short flags);
void					fill_right(char **str, int size);
void					make_str(short flags, int sign, char **nb);
char					*typecast(va_list *argp, short flags, int base);

char					*hexcast(void *arg, short flags, int base);

#endif
