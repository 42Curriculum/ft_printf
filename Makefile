NAME := ft_printf

F_N := main
FLAGS := -Wall -Wextra -Werror

OBJS := $(addprefix objects/, $(addsuffix .o $(F_N)))
FILES := $(addprefix srcs/, $(addsuffix .c $(F_N)))
LIB := libft

LIB_LINK := -L $(LIB) -l ft

INCL := -I libft/ -I incl/

all : ($NAME)

objects%.o : srcs/%.c
	@/bin/mkdir -p objects
	@gcc $(FLAGS) -c $(INCL) $< -o $@

$(NAME) : $(OBJS)
	@make -C $(LIB)
	@gcc $(LIB_LINK) $(OBJS) -o $(NAME)

clean :
	@/bin/rm -rf objects
	@make -C $(LIB) clean

fclean : clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIB) -fclean

re : fclean all