/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 07:58:23 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/06 18:56:34 by jjosephi         ###   ########.fr       */
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
# define FHAS 0x80
# define F0FI 0x100
# define FSTA 0x200
# define FPRE 0x400

union					u_dval
{
	double				type;
	struct
	{
		unsigned long	mantissa	: 52;
		unsigned int	exp			: 11;
		unsigned int	sign		: 1;
	}					bits;
}						u_b_double;

typedef void			t_func(va_list *argp, short flags, int precision[]);

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

void					fill_left(char **str, int precision, short flags);
void					fill_right(char **str, int size);
void					make_str(short flags, int sign, char **nb);
char					*typecast(va_list *argp, short flags, int base);

char					*hexcast(void *arg, short flags, int base);

#endif
