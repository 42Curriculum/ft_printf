/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 08:45:59 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/21 18:25:28 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **aslt, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *next;

	if (*aslt == NULL)
		return ;
	temp = *aslt;
	while (temp)
	{
		next = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = next;
	}
	*aslt = NULL;
	return ;
}
