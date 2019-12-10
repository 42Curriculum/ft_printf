/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 02:45:51 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/09 21:44:34 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/libft.h"

void	ft_str_shift(char **str, int n_shift, char skip)
{
	char	*tmp;
	int		i;
	int		n;

	i = 0;
	n = 0;
	tmp = ft_strdup(*str);
	while (i < n_shift)
	{
		(*str)[i] = skip;
		i++;
	}
	while (tmp[n] == skip)
		n++;
	while ((*str)[i])
	{
		(*str)[i] = tmp[n];
		i++;
		n++;
	}
	free(tmp);
}
