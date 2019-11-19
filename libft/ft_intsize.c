/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:47:38 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/02 11:02:19 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_intsize(long long nb)
{
	unsigned int size;

	size = 0;
	while (nb > 0)
	{
		++size;
		nb /= 10;
	}
	return (size);
}
