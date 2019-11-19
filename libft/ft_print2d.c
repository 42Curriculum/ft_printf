/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:41:41 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/22 18:00:37 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print2d(char **str, char c)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(*str) - 2;
	while (i < l)
	{
		ft_putstr(str[i]);
		i++;
		ft_putchar(c);
	}
	return ;
}
