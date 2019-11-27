NAME = libftprintf.a

F_N = test ft_printf conversions fill_str get_flag
OBJS = $(addprefix objects/, $(addsuffix .o, $(F_N)))
FILES = $(addprefix fdf_srcs/, $(addsuffix .c, $(F_N)))

LIB = libft

LIB_LINK = -L $(LIB) -l ft

INCL = -I libft/
FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

objects/%.o : fdf_srcs/%.c
	@/bin/mkdir -p objects
	@gcc $(FLAGS) -c $(INCL) $< -o $@ 

$(NAME) : $(OBJS)
	@echo  Making libft.. 
	@make -C $(LIB)
	@echo  Compiling..
	@gcc $(LIB_LINK)$(OBJS) -o $(NAME)
	@echo Done!

clean :
	@/bin/rm -rf objects
	@make -C $(LIB) clean 

fclean : clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIB) fclean

re : fclean all