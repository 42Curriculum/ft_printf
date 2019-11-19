/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 09:08:14 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/21 10:52:20 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **aslt, t_list *new)
{
	if (*aslt == NULL)
		*aslt = new;
	else
	{
		new->next = *aslt;
		*aslt = new;
	}
	return ;
}
