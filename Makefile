# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 11:10:07 by thantoni          #+#    #+#              #
#    Updated: 2026/03/05 18:08:03 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

INC_DIR     = includes
LIBFT_DIR   = libft

LIBFT       = $(LIBFT_DIR)/libft.a
IFLAGS      = -I $(INC_DIR) -I $(LIBFT_DIR)
LDFLAGS     = -lreadline

SRCS        =                                         \
                main.c                                \
                mini_bridge/mini_parse.c              \
                mini_bridge/mini_exec.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re