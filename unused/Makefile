NAME			=	push_swap
#CHECKER			=	checker

SRC_DIR			=	src/
LIB_DIR			=	lib/
INCLUDE_DIR		= 	includes/

FILES			=	print_actions1 print_actions2 push_swap \
					sort_push sort_rev_rotate sort_rotate sort_swap \
					sort_three sort_small_data radix_sort_dec radix_sort \
					stack_basic_utils stack_create_utils1 stack_create_utils2 stack_other_utils
#FILES_CHECKER	=	checker sort_push sort_rev_rotate sort_rotate sort_swap \
#					stack_basic_utils stack_create_utils1 stack_create_utils2 stack_other_utils


SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
#SRCS_CHECKER	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES_CHECKER)))
# OBJS			=	$(addprefix $(SRC_DIR), $(addsuffix .o, $(FILES)))

# To call library 'libft.a', you must remove 'lib' prefix and '.a' suffix from its name
LIBRARY			=	ft

CC				=	gcc
INCLUDE			=	-I $(INCLUDE_DIR)
CFLAGS			=	-Werror -Wall -Wextra
RM				=	rm -f

# This rule must be over all
#all		:	$(NAME) $(CHECKER)
all		:	$(NAME)

$(NAME)	: 	
			@make -C $(LIB_DIR) --silent
			$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) -L $(LIB_DIR) -l $(LIBRARY) -o $(NAME)

#$(CHECKER) :	
#			@make -C $(LIB_DIR) --silent
#			$(CC) $(CFLAGS) $(SRCS_CHECKER) $(INCLUDE) -L $(LIB_DIR) -l $(LIBRARY) -o $(CHECKER)

#bonus	:	$(CHECKER)

clean	:
			@make -C $(LIB_DIR) clean --silent
			$(RM) $(OBJS)

fclean	:	clean
			@make -C $(LIB_DIR) fclean --silent
			$(RM) $(NAME)
#			$(RM) $(NAME) $(CHECKER)

re		:	fclean all

.PHONY	:	all clean fclean re

# http://nuclear.mutantstargoat.com/articles/make/#multiple-source-directories