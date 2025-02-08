#include "so_long.h"

int error(char *msg)
{
    ft_printf("\033[0;31m" "Error\n    %s\n" "\033[0m", msg);
    return (0);
}