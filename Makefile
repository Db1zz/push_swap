# Project settings
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address -g
SRCS =	chunk.c			\
		list.c			\
		main.c			\
		pivot.c			\
		rotate.c		\
		simple_sort.c 	\
		stack_utils.c	\
		utils.c			\
		chunk_utils.c	\
		list_utils.c	\
		parser.c		\
		push.c			\
		rotate_utils.c	\
		sort.c			\
		swap.c			\

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re