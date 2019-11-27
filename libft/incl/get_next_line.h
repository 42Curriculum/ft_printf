/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:43:38 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/28 20:16:34 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 500
# define FD_NOTMAX 4094
# define TRUE 1
# define FALSE 0
# include "libft.h"
# include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif
