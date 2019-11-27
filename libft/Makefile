# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 12:29:56 by jjosephi          #+#    #+#              #
#    Updated: 2019/11/19 07:45:21 by jjosephi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
INCL = -I incl/
all : $(NAME)

$(NAME) :
	@gcc -c $(FLAGS) *.c $(INCL)
	@ar rc libft.a *.o

compile :
	@gcc $(FLAGS) *.c

clean :
	@/bin/rm -f *.o

fclean : clean
	@/bin/rm -f libft.a

re : fclean $(NAME)
