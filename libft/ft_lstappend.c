/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:20:02 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/22 18:20:18 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list *lst, t_list *elem)
{
	t_list *copy;

	copy = lst;
	elem->next = NULL;
	while (copy->next != '\0')
		copy = copy->next;
	copy->next = elem;
	return ;
}
