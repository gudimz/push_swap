.PHONY:		all re clean fclean debug

PS_NAME = push_swap
CH_NAME = checker
SRCDIR = ./src/
PS_DIR = push_swap/
CH_DIR = checker/
CMD_DIR = command/
LIBFT_DIR = ./libft/
LIBFT = libft.a
INCLD_LIBFT = -I ./libft/includes/
INCLD = -I ./includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLD) $(INCLD_LIBFT) -O3 -MD

PS_FILES = main.c check_input.c add_order.c big_sort_stack.c small_sort_stack.c

CH_FILES = main.c check_input.c exec_cmd.c

CMD_FILES = push.c swap.c rotate.c rev_rotate.c

PS_SRC = $(addprefix $(SRCDIR)$(PS_DIR), $(PS_FILES)) $(addprefix $(SRCDIR)$(CMD_DIR), $(CMD_FILES))
CH_SRC = $(addprefix $(SRCDIR)$(CH_DIR), $(CH_FILES)) $(addprefix $(SRCDIR)$(SRC_DIR)$(CMD_DIR), $(CMD_FILES))

PS_OBJS = $(PS_SRC:.c=.o)
PS_D_FILES = $(PS_SRC:.c=.d)

CH_OBJS = $(CH_SRC:.c=.o)
CH_D_FILES = $(CH_SRC:.c=.d)


all: $(PS_NAME)

$(PS_NAME): $(PS_OBJS) | tools
		$(CC) $(CFLAGS) $(LIBFT_DIR)$(LIBFT) $(PS_OBJS) -o $(PS_NAME)
include $(wildcard $(PS_D_FILES))

bonus: $(CH_NAME)

$(CH_NAME): $(CH_OBJS) | tools
		$(CC) $(CFLAGS) $(LIBFT_DIR)$(LIBFT) $(CH_OBJS) -o $(CH_NAME)
include $(wildcard $(CH_D_FILES))

tools:
		make -C $(LIBFT_DIR)

debug: CFLAGS += -fsanitize=address -g
debug: all

clean:
		rm -f $(PS_OBJS) $(CH_OBJS) $(PS_D_FILES) $(CH_D_FILES)
		make -C $(LIBFT_DIR) clean
fclean: clean
		rm -f ${PS_NAME} ${CH_NAME}
		make -C $(LIBFT_DIR) fclean

re: fclean all
