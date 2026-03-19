# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 17:45:11 by cn-goie           #+#    #+#              #
#    Updated: 2025/12/16 17:49:01 by cn-goie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CHECKER     = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCLUDES    = -I. -Ilibft

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR     = srcs
BONUS_DIR   = bonus

SRCS        = \
    $(SRC_DIR)/main.c \
    $(SRC_DIR)/parsing.c \
    $(SRC_DIR)/stack_init.c \
    $(SRC_DIR)/operations/sa.c \
    $(SRC_DIR)/operations/sb.c \
    $(SRC_DIR)/operations/ss.c \
    $(SRC_DIR)/operations/pa.c \
    $(SRC_DIR)/operations/pb.c \
    $(SRC_DIR)/operations/ra.c \
    $(SRC_DIR)/operations/rb.c \
    $(SRC_DIR)/operations/rr.c \
    $(SRC_DIR)/operations/rra.c \
    $(SRC_DIR)/operations/rrb.c \
    $(SRC_DIR)/operations/rrr.c \
    $(SRC_DIR)/algo/lis.c \
    $(SRC_DIR)/algo/cost.c \
    $(SRC_DIR)/algo/sort.c

BONUS_SRCS  = \
    $(BONUS_DIR)/checker.c

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
    make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS)
    $(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(CHECKER)

clean:
    rm -f $(OBJS) $(BONUS_OBJS)
    make -C $(LIBFT_DIR) clean

fclean: clean
    rm -f $(NAME) $(CHECKER)
    make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re