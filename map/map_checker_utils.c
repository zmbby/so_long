#include "map.h"

int valid_char(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'
        || c == 'H' || c == 'V' || c == 'F')
        return (1);
    return (0);
}

int valid_uniquechar(char c, char checker, int bool)
{
    if (c == checker && bool == 0)
        bool = 1;
    else if (c == checker && bool == 1)
        return (0);
    return (1);
}

int valid_border(char c, t_vector point, t_vector size)
{
    if (point.y == 0 || point.x == 0 
        || point.y == size.y - 1 || point.x == size.x - 1)
        if (c != '1')
            return (0);
    return (1);
}