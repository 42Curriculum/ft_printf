/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:59:03 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/19 17:23:17 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str, const char *str2)
{
	int i;

	i = 0;
	while ((unsigned char)str[i] == (unsigned char)str2[i] && str[i] != '\0'
	&& str2[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)str[i] - (unsigned char)str2[i]);
}
