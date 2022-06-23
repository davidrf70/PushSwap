NAME	=	push_swap

LIB_DIR	=	libft/
SRC_DIR	= 	srcs/
OBJ_DIR	=	objs/

PUSH_FILES	= 	push_swap print_actions \
				sort_push sort_rev_rotate sort_rotate sort_swap \
				sort_three sort_small_data radix_sort \
				stack_basic_utils stack_create_utils stack_other_utils
CHECK_FILES	=	checker stack_basic_utils stack_create_utils stack_other_utils

PUSH_SRCS	=	$(addsuffix .c, $(PUSH_FILES))
PUSH_OBJS	=	$(addsuffix .o, $(PUSH_FILES))
CHECK_SRCS	=	$(addsuffix .c, $(CHECK_FILES))
CHECK_OBJS	=	$(addsuffix .c, $(CHECK_FILES))
				