DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
GREEN = \033[0;92m

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft
RM = rm -f

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
SRC_DIR = src/

SRC_FILES = main.c \
            utils.c \
            parsing/parsing.c \
            stack/create_node.c \
            stack/stack_utils.c \
            sort/k-sort.c \
            sort/sort_five.c \
            sort/sort_three.c \
            sort/sort_utils.c \
            operations/pa.c operations/pb.c operations/ra.c operations/rb.c \
            operations/rr.c operations/rra.c operations/rrb.c operations/rrr.c \
            operations/sa.c operations/sb.c operations/ss.c

OBJ = $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ)
	@echo "$(YELLOW)Objects cleaned!$(DEF_COLOR)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(YELLOW)Executable cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re