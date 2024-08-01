NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
SRCS =  $(wildcard ./*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re