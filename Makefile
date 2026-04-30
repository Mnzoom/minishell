# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 11:10:07 by thantoni          #+#    #+#              #
#    Updated: 2026/04/30 21:24:52 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

CMD_CC	=	cc -Wall -Wextra -Werror -g3
CMD_RM	=	rm -rf

FLAGS_INCLUDES	=	-I includes -I libft
FLAGS_READLINE	=	-lreadline

PATH_LIBFT = libft/

LIBFT	=	$(PATH_LIBFT)libft.a

SRCS__MAIN			=	main.c																	\
						main_cache_envp.c														\
						main_inputs_handling.c

SRCS__T_ENV			=	t_env/t_env__add_back.c 												\
						t_env/t_env__extract_by_key.c 											\
						t_env/t_env__free_all.c 												\
						t_env/t_env__free.c														\
						t_env/t_env__get_by_key.c 												\
						t_env/t_env__get_size.c 												\
						t_env/t_env__m_new.c 													\
						t_env/t_env__print_all.c 												\
						t_env/t_env__print.c 													\
						t_env/t_env__remove_by_key.c 											\
						t_env/env_is_key_valid.c												\
						t_env/t_env__to_m_array.c												\
						t_env/t_env__internal/env_extract_m_key.c 								\
						t_env/t_env__internal/env_extract_m_value.c

SRCS__MINI_PARSE	=	mini_parse/cmd_shipper/cmd_shipper.c 									\
						mini_parse/t_token/t_token__m_free_all.c 								\
						mini_parse/t_token/t_token__m_free.c 									\
						mini_parse/t_token/t_token__m_new.c 									\
						mini_parse/t_token/t_token__parse_value_str.c 							\
						mini_parse/t_token/t_token__print.c										\
						mini_parse/token_refinery/token_refinery.c 								\
						mini_parse/token_refinery/handle_modifs.c 								\
						mini_parse/token_refinery/compute_modifs_len.c 							\
						mini_parse/token_refinery/get_var_name_len.c 							\
						mini_parse/token_refinery/get_lastsig_len.c 							\
						mini_parse/token_refinery/ft_isenvpattern.c 							\
						mini_parse/token_refinery/ft_issigpattern.c 							\
						mini_parse/token_refinery/ft_isenvchar.c 								\
						mini_parse/token_verifier/token_verifier.c 								\
						mini_parse/tokenizer/tokenizer.c 										\

SRCS__MINI_EXEC		=	mini_exec/apply_redirections.c											\
						mini_exec/exec_builtin.c 												\
						mini_exec/exec_child_process.c											\
						mini_exec/exec_cmds.c 													\
						mini_exec/get_m_path.c													\
						mini_exec/exec_pipe.c													\
						mini_exec/read_heredoc.c

SRCS__MINI_BRIDGE	=	mini_bridge/mini_exec.c 												\
						mini_bridge/mini_parse.c 												\
						mini_bridge/t_cmd/t_cmd__add_m_redirect.c 								\
						mini_bridge/t_cmd/t_cmd__m_new.c 										\
						mini_bridge/t_cmd/t_cmd__print.c 										\
						mini_bridge/t_redirect/t_redirect__m_new.c 								\
						mini_bridge/t_token_type/t_token_type__is_redirection.c 				\
						mini_bridge/t_token_type/t_token_type__to_str.c

SRCS__MINI_BUILTSIN	=	mini_builtsin/is_builtin.c												\
						mini_builtsin/mini_echo.c 												\
						mini_builtsin/mini_cd.c 												\
						mini_builtsin/mini_unset.c												\
						mini_builtsin/mini_pwd.c 												\
						mini_builtsin/builtin_env.c 											\
						mini_builtsin/mini_export.c												\
						mini_builtsin/mini_export__internal/handle_env_export.c 				\
						mini_builtsin/mini_export__internal/handle_env_sorted_print.c 			\
						mini_builtsin/mini_exit.c

SRCS				=	$(SRCS__MAIN)															\
						$(SRCS__T_ENV)															\
						$(SRCS__MINI_PARSE)														\
						$(SRCS__MINI_EXEC)														\
						$(SRCS__MINI_BRIDGE)													\
						$(SRCS__MINI_BUILTSIN)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

macOS: IFLAGS += -I$(shell brew --prefix readline)/include
macOS: LDFLAGS += -L$(shell brew --prefix readline)/lib
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