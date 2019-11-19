/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:07:09 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/02 10:50:04 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	char			*str;
	long long		n;
	unsigned int	size;

	if (nbr == 0)
		return (ft_strdup("0"));
	n = (long long)nbr;
	if (nbr < 0)
		n *= -1;
	size = ft_intsize(n) + (nbr < 0);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (nbr < 0)
		str[0] = '-';
	str[size] = '\0';
	while (n > 0)
	{
		str[--size] = (char)(n % 10 + 48);
		n /= 10;
	}
	return (str);
}
