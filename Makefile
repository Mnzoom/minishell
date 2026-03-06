# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 11:10:07 by thantoni          #+#    #+#              #
#    Updated: 2026/03/06 17:50:02 by thantoni         ###   ########.fr        #
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

SRCS        =																\
                main.c														\
				main_inputs_handling.c										\
                mini_bridge/mini_parse.c              						\
                mini_bridge/mini_exec.c										\
				mini_parse/t_token/t_token__parse_value_str.c				\
				mini_parse/t_token/t_token.c								\
				mini_parse/t_token_type/t_token_type__is_redirection.c		\
				mini_parse/token_verifier/token_verifier.c					\
				mini_parse/tokenizer/tokenizer.c							\

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