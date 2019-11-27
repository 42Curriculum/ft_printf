/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 07:48:49 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/27 00:33:50 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/incl/libft.h"
#include "ft_printf.h"

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
				i += read_chars((char *)(str + i), &argp);
			}
		}
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}
