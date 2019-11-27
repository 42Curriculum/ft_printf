/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:41:46 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/27 03:56:33 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_left(char **str, int precision, short flags, char *message)
{
	int i;

	i = 0;
	while (i < precision)
	{
		if (0b0000001000000000 & flags)
			(*str)[i] = '0';
		else
			(*str)[i] = ' ';
		i++;
	}
	*str = ft_strcat(*str, message);
}

void	fill_right(char **str, short flags, int size, char *message)
{
	int i;

	i = ft_strlen(*str);
	while (i < size)
	{
		(*str)[i] = ' ';
		i++;
	}
}