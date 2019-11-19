/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 01:34:50 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/18 13:42:08 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_better_strjoin(char *str1, char *str2)
{
	char *new;

	new = ft_strjoin(str1, str2);
	free(str1);
	return (new);
}
