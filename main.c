








#include "minishell.h"

int	main(int argc, char **argv)
{
	mini_exec(mini_parse(argc, argv));
	return (EXIT_SUCCESS);
}