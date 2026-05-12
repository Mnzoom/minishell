# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 11:10:07 by thantoni          #+#    #+#              #
#    Updated: 2026/05/12 05:37:42 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

CMD_CC	=	cc -Wall -Wextra -Werror -g3
CMD_RM	=	rm -rf

FLAGS_INCLUDES	=	-I includes -I libft
FLAGS_READLINE	=	-lreadline

PATH_LIBFT = includes/libft/

LIBFT	=	$(PATH_LIBFT)libft.a

SRCS__MAIN			=	main.c																	\
						main_cache_envp.c														\
						main_inputs_handling.c													\
						minishell_exit.c

SRCS__MINI_PARSE	=	mini_parse/cmd_shipper/cmd_shipper.c 									\
						mini_parse/t_parse_info/t_parse_info__init.c 							\
						mini_parse/t_token/t_token__m_free_all.c 								\
						mini_parse/t_token/t_token__m_free.c 									\
						mini_parse/t_token/t_token__m_new.c 									\
						mini_parse/t_token/t_token__parse_value_str.c 							\
						mini_parse/token_refinery/token_refinery.c 								\
						mini_parse/token_refinery/handle_modifs.c 								\
						mini_parse/token_refinery/modif_expand_env.c							\
						mini_parse/token_refinery/modif_expand_sig.c							\
						mini_parse/token_refinery/modif_handle_quote_skip.c						\
						mini_parse/token_refinery/compute_modifs_len.c 							\
						mini_parse/token_refinery/get_var_name_len.c 							\
						mini_parse/token_refinery/get_lastsig_len.c 							\
						mini_parse/token_refinery/ft_isenvpattern.c 							\
						mini_parse/token_refinery/ft_issigpattern.c 							\
						mini_parse/token_refinery/ft_isenvchar.c 								\
						mini_parse/token_refinery/token_splitter.c								\
						mini_parse/token_verifier/token_verifier.c 								\
						mini_parse/tokenizer/tokenizer.c

SRCS__MINI_EXEC		=	mini_exec/apply_redirections.c											\
						mini_exec/exec_builtin.c 												\
						mini_exec/exec_child_process.c											\
						mini_exec/get_m_path.c													\
						mini_exec/exec_pipe.c													\
						mini_exec/t_heredoc_info/t_heredoc_info__init.c							\
						mini_exec/heredoc_handler/handle_heredocs.c								\
						mini_exec/heredoc_handler/handle_heredocs_child.c						\
						mini_exec/mini_builtsin/is_builtin.c									\
						mini_exec/mini_builtsin/mini_echo.c 									\
						mini_exec/mini_builtsin/mini_cd.c 										\
						mini_exec/mini_builtsin/mini_unset.c									\
						mini_exec/mini_builtsin/mini_pwd.c 										\
						mini_exec/mini_builtsin/builtin_env.c 									\
						mini_exec/mini_builtsin/mini_export.c									\
						mini_exec/mini_builtsin/mini_export__internal/handle_env_export.c 		\
						mini_exec/mini_builtsin/mini_export__internal/handle_env_sorted_print.c \
						mini_exec/mini_builtsin/mini_exit.c

SRCS__MINI_BRIDGE	=	mini_bridge/mini_exec.c 												\
						mini_bridge/mini_parse.c 												\
						mini_bridge/t_cmd/t_cmd__m_new.c 										\
						mini_bridge/t_cmd/t_cmd__free.c 										\
						mini_bridge/t_cmd/t_cmd__freeall.c 										\
						mini_bridge/t_cmd/t_cmd__add_m_redirect.c 								\
						mini_bridge/t_redirect/t_redirect__m_new.c 								\
						mini_bridge/t_redirect/t_redirect__free.c 								\
						mini_bridge/t_redirect/t_redirect__freeall.c 							\
						mini_bridge/t_token_type/t_token_type__is_redirection.c 				\
						mini_bridge/t_token_type/t_token_type__to_str.c							\
						mini_bridge/t_env/t_env__add_back.c 									\
						mini_bridge/t_env/t_env__extract_by_key.c 								\
						mini_bridge/t_env/t_env__free_all.c 									\
						mini_bridge/t_env/t_env__free.c											\
						mini_bridge/t_env/t_env__get_by_key.c 									\
						mini_bridge/t_env/t_env__get_size.c 									\
						mini_bridge/t_env/t_env__m_new.c 										\
						mini_bridge/t_env/t_env__print_all.c 									\
						mini_bridge/t_env/t_env__print.c 										\
						mini_bridge/t_env/t_env__remove_by_key.c 								\
						mini_bridge/t_env/env_is_key_valid.c									\
						mini_bridge/t_env/t_env__to_m_array.c									\
						mini_bridge/t_env/t_env__internal/env_extract_m_key.c 					\
						mini_bridge/t_env/t_env__internal/env_extract_m_value.c					\
						mini_bridge/t_gc/t_gc__add.c											\
						mini_bridge/t_gc/t_gc__extract.c										\
						mini_bridge/t_gc/t_gc__free.c											\
						mini_bridge/t_gc/t_gc__freeall.c										\
						mini_bridge/t_gc/t_gc__get.c											\
						mini_bridge/t_gc/t_gc__m_new.c											\
						mini_bridge/t_gc/t_gc__malloc.c											\
						mini_bridge/t_gc/t_gc__calloc.c											\
						mini_bridge/t_gc/t_gc__remove.c											\
						mini_bridge/t_gc/t_gc__strdup.c											\
						mini_bridge/t_gc/t_gc__singleton.c

SRCS				=	$(SRCS__MAIN)															\
						$(SRCS__MINI_PARSE)														\
						$(SRCS__MINI_EXEC)														\
						$(SRCS__MINI_BRIDGE)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

macOS: FLAGS_INCLUDES += -I$(shell brew --prefix readline)/include
macOS: FLAGS_READLINE += -L$(shell brew --prefix readline)/lib
macOS: all

$(LIBFT):
	$(MAKE) -C $(PATH_LIBFT)

$(NAME): $(LIBFT) $(OBJS)
	$(CMD_CC) $(OBJS) $(LIBFT) $(FLAGS_READLINE) -o $(NAME)

%.o: %.c
	$(CMD_CC) $(FLAGS_INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(PATH_LIBFT) clean
	$(CMD_RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(PATH_LIBFT) fclean
	$(CMD_RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re