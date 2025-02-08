#include "map.h"
#include "../so_long.h"

static  int file_linecount(char *file)
{
    int     lncount;
    int     fd;
    int     rdcount;
    char    c;

    fd = open(file, O_RDONLY);
    if (!fd)
        return (-1);
    lncount = 1;
    while (1)
    {
        rdcount = read(fd, &c, 1);
        if (rdcount == 0)
            break;
        if (rdcount < 0)
            return (-1);
        if (c == '\n')
            lncount++;
    }
    close(fd);
    return (lncount);
}

static char **alloc_columns(char *file)
{
    char    **map;
    int     line_count;

    line_count = file_linecount(file);
    if (line_count <= 0)
        return (error("open or reading error, the file may not exist !"), NULL);
    map = malloc(sizeof(char *) * (line_count + 1));
    if (!map)
        return (error("malloc faild ! ps: on alloc_map()"), NULL);
    return (map);
}

char    **read_map(char *file)
{
    char    **map;
    int     fd;
    int     i;

    map = alloc_columns(file);
    if (!map)
        return (NULL);
    fd = open(file, O_RDONLY);
    i = 0;
    while ((map[i++] = get_next_line(fd)))
        ;
    map[i] = NULL;
    close(fd);
    return (map);
}