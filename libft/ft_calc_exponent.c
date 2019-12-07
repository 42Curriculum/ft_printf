/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_exponent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:18:06 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/01 19:25:27 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_calc_exponent(int mult, int exp)
{
	int			i;
	long long	num;
	int			sign;

	sign = 1;
	(exp > 0) ? (sign *= 1) : (sign *= -1);
	exp *= sign;
	num = mult;
	i = 2;
	if (exp == 0)
		return (0);
	else if (exp == 1 || mult == 1)
		return (mult);
	else
	{
		while (i <= exp)
		{
			num *= num;
			i++;
		}
	}
	return (mult *= sign);
}
