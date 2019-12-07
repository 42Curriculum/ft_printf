/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 02:35:54 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/05 03:44:28 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/libft.h"

void	ft_strmult(char **str, int multiplier, int i)
{
	int carry;
	int current;

	carry = 0;
	while (i >= 0)
	{
		if (!(ft_isdigit((*str)[i])))
			i--;
		if ((current = ((*str)[i] - '0') * multiplier) + carry >= 10)
		{
			(*str)[i] = ((current + carry) % 10) + '0';
			carry = (current + carry) / 10;
		}
		else
		{
			(*str)[i] = ((((*str)[i] - '0') * multiplier) + carry) + '0';
			carry = 0;
		}
		i--;
	}
	if (carry > 0)
	{
		ft_str_shift(str, 1, '0');
		*str[0] = carry;
	}
}
