/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:26:49 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/06 14:27:01 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_str_add(char **str, int add, int i)
{
	int current;
	int carry;

	current = 0;
	carry = add;
	while (--i > 0)
	{
		if ((carry + (current = ((*str)[i] - '0')) >= 10))
		{
			carry = ((current + carry) - ((*str)[i] - '0'));
			(*str)[i] = ((current + carry) - 10) + '0';
		}
		else
		{
			(*str)[i] = (((*str)[i] - '0') + carry) + '0';
			carry = 0;
			break ;
		}
	}
}
