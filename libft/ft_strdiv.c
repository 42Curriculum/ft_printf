/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdiv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 02:34:06 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/05 22:27:03 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/libft.h"

void	ft_strdiv(char **str, int multiplier)
{
	int i;
	int current;
	int test;
	int dot;
	
	i = 0;
	current = 0;
	dot = 0;
	while ((*str)[i])
	{
		if (!(ft_isdigit((*str)[i])))
		{
			if (dot == 0)
			{
				if ((*str)[i] == '.')
					dot = 1;
				else
					dot = 1;
				(*str)[i] = '.';
				i++;
			}
		}
		if (!(ft_isdigit((*str)[i])))
			(*str)[i] = '0';
		test = (((*str)[i] - '0') + current) / multiplier;
		current = (((*str)[i] - '0') + current) % multiplier;
		(*str)[i] =  test + '0';
		current = (current * 10);
		i++;
	}
}