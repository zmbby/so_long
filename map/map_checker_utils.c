#include "map.h"

int valid_char(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'
        || c == 'H' || c == 'V' || c == 'F' || c == '\n')
        return (1);
    return (0);
}

int valid_uniquechar(char c, int *b_player)
{
    if (c == 'P' && *b_player == 0)
        *b_player = 1;
    else if (c == 'P' && *b_player == 1)
        return (0); 
    return (1);
}

int valid_border(char**map, int y, t_vector size)
{
    return (map[y][0] == '1' && map[y][size.x - 2] == '1');
}