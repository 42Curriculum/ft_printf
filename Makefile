NAME = libftprintf.a

F_N = ft_printf conversions conversions_v2 f_flag f_lflag fill_str get_flag 
OBJS = $(addprefix objects/, $(addsuffix .o, $(F_N)))
FILES = $(addprefix srcs/, $(addsuffix .c, $(F_N)))

LIB = libft

LIB_LINK = -L $(LIB) -l ft

INCL = -I libft/incl/ -I incl/
FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

objects/%.o : srcs/%.c
	@/bin/mkdir -p objects
	@gcc $(FLAGS) -c $(INCL) $< -o $@ 

$(NAME) : $(OBJS)
	@echo  Making libft.. 
	@make -C $(LIB)
	@echo  Compiling..
	@ar rc $(NAME) $(OBJS)
	@echo Done!

clean :
	@/bin/rm -rf objects
	@make -C $(LIB) clean 

fclean : clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIB) fclean

re : fclean all