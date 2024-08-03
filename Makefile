# Project settings
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
SRCS =  $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Tests settings
TEST_NAME = test
TEST_CC = cc
TEST_CFLAGS = -Wall -Wextra -fsanitize=address
TEST_SRCS = $(filter-out push_swap.c, $(wildcard *.c)) $(wildcard ./tests/*.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)

all: $(PRINTF) $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

test: $(PRINTF)
	@mkdir -p temp_printf_objs
	@cd temp_printf_objs && ar x ../$(PRINTF)
	$(TEST_CC) $(TEST_CFLAGS) $(PRINTF) $(TEST_SRCS) -o $(TEST_NAME)
	@rm -rf temp_printf_objs

.PHONY: all clean fclean re