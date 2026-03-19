# --- IDENTITÉ ---
NAME        = push_swap

# --- DOSSIERS ---
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = .

# --- SOURCES ---
# On liste les fichiers en utilisant le chemin relatif depuis SRC_DIR
SRCS_FILES  = main.c \
              utils.c \
              parsing/parsing.c \
              stack/create_node.c \
              stack/stack_utils.c \
              operations/sa.c operations/sb.c operations/ss.c \
              operations/pa.c operations/pb.c \
              operations/ra.c operations/rb.c operations/rr.c \
              operations/rra.c operations/rrb.c operations/rrr.c \
              sort/radix.c \
              sort/sort_three.c \
              sort/sort_utils.c \
              sort/sort_five.c \

# Transformation des .c en .o dans le dossier OBJ_DIR
SRCS        = $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS        = $(SRCS_FILES:%.c=$(OBJ_DIR)/%.o)

# --- COMPILATION ---
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)
RM          = rm -rf

# --- COULEURS ---
GREEN       = \033[0;32m
BLUE        = \033[0;34m
RESET       = \033[0m

# --- RÈGLES ---

all: $(LIBFT) $(NAME)

# Compilation de la libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Linkage final
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✓ push_swap compilé avec succès !$(RESET)"

# Compilation des objets avec création auto des dossiers
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(BLUE)Objets supprimés.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(BLUE)Exécutable et libft.a supprimés.$(RESET)"

re: fclean all

.PHONY: all clean fclean re