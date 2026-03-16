# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 11:10:07 by thantoni          #+#    #+#              #
#    Updated: 2026/03/16 15:53:48 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -rf

INC_DIR     = includes
LIBFT_DIR   = libft

LIBFT       = $(LIBFT_DIR)/libft.a
IFLAGS      = -I $(INC_DIR) -I $(LIBFT_DIR)
LDFLAGS     = -lreadline

SRCS        =                                                               \
                main.c     													\
				main_cache_envp.c											\
                main_inputs_handling.c                                      \
                mini_bridge/mini_parse.c                                    \
                mini_bridge/mini_exec.c                                     \
				mini_builtsin/mini_echo/mini_echo.c							\
				mini_builtsin/mini_export/mini_export.c						\
				mini_builtsin/mini_export/handle_env_export.c				\
				mini_builtsin/mini_export/handle_env_sorted_print.c			\
				mini_builtsin/mini_unset/mini_unset.c						\
				mini_parse/cmd_shipper/cmd_shipper.c						\
				mini_parse/t_cmd/t_cmd__add_m_redirect.c					\
				mini_parse/t_cmd/t_cmd__m_new.c								\
				mini_parse/t_cmd/t_cmd__print.c								\
				mini_parse/t_redirect/t_redirect__m_new.c					\
                mini_parse/t_token/t_token__m_free_all.c                    \
                mini_parse/t_token/t_token__m_free.c                        \
                mini_parse/t_token/t_token__m_new.c                         \
                mini_parse/t_token/t_token__parse_value_str.c               \
                mini_parse/t_token/t_token__print.c                         \
                mini_parse/t_token_type/t_token_type__is_redirection.c      \
                mini_parse/t_token_type/t_token_type__to_str.c				\
                mini_parse/token_refinery/token_refinery.c                  \
                mini_parse/token_refinery/handle_modifs.c					\
                mini_parse/token_refinery/compute_modifs_len.c				\
                mini_parse/token_refinery/get_var_name_len.c				\
                mini_parse/token_verifier/token_verifier.c                  \
                mini_parse/tokenizer/tokenizer.c                            \
				t_env/t_env__add_back.c										\
				t_env/t_env__extract_by_key.c								\
				t_env/t_env__free_all.c										\
				t_env/t_env__free.c											\
				t_env/t_env__get_by_key.c									\
				t_env/t_env__get_size.c										\
				t_env/t_env__m_new.c										\
				t_env/t_env__print_all.c									\
				t_env/t_env__print.c										\
				t_env/t_env__remove_by_key.c								\
				utils/env_parsing/env_extract_m_key.c						\
				utils/env_parsing/env_extract_m_value.c						\
				utils/env_parsing/env_is_key_valid.c						\

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

macOS: IFLAGS += -I$(shell brew --prefix readline)/include
macOS: LDFLAGS += -L$(shell brew --prefix readline)/lib
macOS: all

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