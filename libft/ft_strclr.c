/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:47:57 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/01 11:41:48 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while ((int)len-- >= 0)
		s[len] = '\0';
	return ;
}
