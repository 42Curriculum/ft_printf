/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:27:51 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/19 19:02:20 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (n > 0 && str[i] && str2[i] && str[i] == str2[i])
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)str[i] - (unsigned char)str2[i]);
}
