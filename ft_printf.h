/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 07:58:23 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/27 01:58:28 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef void func(va_list *argp, short flags, int precision);

int     ft_printf(const char *str, ...);

int		read_chars(char *str, va_list *argp);

void	conv_s(va_list *argp, short flags, int precision);
void	conv_c(va_list *argp, short flags, int prec);

void	fill_left(char **str, int precision, short flags, char *message);
void	fill_right(char **str, short flags, int size, char *message);

#endif