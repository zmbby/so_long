#include "so_long.h"

int error(char *msg)
{
    ft_printf("\033[0;31m" "Error\n    %s\n" "\033[0m", msg);
    return (0);
}

/* Returns NULL printing <message> in red */
void	*null_error(char *message)
{
	ft_printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (0);
}

/* Prints <message> in yellow */
void	print_warning(char *message)
{
	ft_printf("\033[0;33m" " Warning\n %s\n" "\033[0m", message);
}