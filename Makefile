# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 11:10:07 by thantoni          #+#    #+#              #
#    Updated: 2026/03/09 17:28:12 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -rf

INC_DIR     = includes
LIBFT_DIR   = libft

# 1. On récupère le chemin de readline installé par brew
READLINE_DIR = $(shell brew --prefix readline)

LIBFT       = $(LIBFT_DIR)/libft.a
# 2. On ajoute le dossier "include" de readline pour la compilation des .c
IFLAGS      = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(READLINE_DIR)/include
# 3. On ajoute le dossier "lib" de readline pour l'édition de liens finale
LDFLAGS     = -L $(READLINE_DIR)/lib -lreadline

SRCS        =                                                               \
                main.c                                                      \
                main_inputs_handling.c                                      \
                mini_bridge/mini_parse.c                                    \
                mini_bridge/mini_exec.c                                     \
                mini_parse/t_token/t_token__m_free_all.c                    \
                mini_parse/t_token/t_token__m_free.c                        \
                mini_parse/t_token/t_token__m_new.c                         \
                mini_parse/t_token/t_token__parse_value_str.c               \
                mini_parse/t_token/t_token__print.c                         \
                mini_parse/t_token_type/t_token_type__is_redirection.c      \
                mini_parse/t_token_type/t_token_type__to_str.c      \
                mini_parse/token_refinery/token_refinery.c                  \
                mini_parse/token_verifier/token_verifier.c                  \
                mini_parse/tokenizer/tokenizer.c                            \

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re