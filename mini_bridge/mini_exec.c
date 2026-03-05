
#include "mini_bridge.h"
#include <stdio.h>

void	mini_exec(t_cmd *cmd_linked_list)
{
	t_cmd	*cmd_node;
	size_t	cmd_i;

	cmd_node = cmd_linked_list;
	cmd_i = 0;
	while(cmd_node != NULL)
	{
		size_t	arg_i;

		arg_i = 1;
		printf("cmd[%lu]: %s\n", cmd_i, cmd_node->args[0]);
		while (cmd_node->args[arg_i] != NULL)
		{
			printf("\t\t- arg[%lu]: %s\n", arg_i, cmd_node->args[arg_i]);
			arg_i++;
		}
		cmd_node = cmd_node->next;
		cmd_i++;
	}
}