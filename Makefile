.PHONY:		all re clean fclean norme debug

NAME = push_swap
SRCDIR = ./src/
CMDDIR = $(SRCDIR)command/
LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a
INCLD_LIBFT = -I ./libft/includes/
INCLD = -I ./includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLD) $(INCLD_LIBFT) -O3 -MD

FILES_SWAP = main.c check_input.c add_order.c big_sort_stack.c small_sort_stack.c

FILES_CMD = push.c swap.c rotate.c rev_rotate.c

SRC_SWAP = $(addprefix $(SRCDIR), $(FILES_SWAP)) $(addprefix $(CMDDIR), $(FILES_CMD))
OBJS = $(SRC_SWAP:.c=.o)
D_FILES = $(SRC_SWAP:.c=.d)

all: $(NAME)

$(NAME): $(OBJS) | tools
		$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
include $(wildcard $(D_FILES))

tools:
		make -C $(LIBFTDIR)

debug: CFLAGS += -fsanitize=address -g
debug: all

clean:
		rm -f $(OBJS) $(D_FILES)
		make -C $(LIBFTDIR) clean
fclean: clean
		rm -f ${NAME}
		make -C $(LIBFTDIR) fclean

re: fclean all
