#include "map.h"

t_tile  **alloc_tilemap(char **map)
{
    t_tile  **tilemap;
    int     i;

    tilemap = malloc(sizeof(t_tile *) * (ft_chartable_linecount(map) + 1));
    if (tilemap == NULL)
        return (NULL);
    i = 0;
    while (map[i] != NULL)
    {
        tilemap[i] = malloc(sizeof(t_tile) * (ft_strlen(*map) + 1));
        if (tilemap == NULL)
        {
            while (i > 0)
                free(tilemap[i--]);
            return (NULL);
        }
        i++;
    }
    return (tilemap);
}

t_tiletype  define_tiletype(char definer)
{
    if (definer == '1')
        return (WALL);
    if (definer == 'C')
        return (COIN);
    if (definer == 'P')
        return (PLAYER);
    if (definer == 'E')
        return (EXIT);
    if (definer == 'H' || definer == 'V')
        return (ENEMY);
    else if (definer == 'F')
        return (FOLLOWER);
    return (EMPTY);
}

void    setup_tile(t_tile **tilemap, int x, int y)
{
    tilemap[y][x].og_type = tilemap[y][x].type;
    tilemap[y][x].position.x = x * IMG_SIZE;
    tilemap[y][x].position.y = y * IMG_SIZE;
    if (y != 0)
        tilemap[y][x].up = &tilemap[y - 1][x];
    if (tilemap[y + 1][x])

}

t_tile  **generate_tilemap(char **map, t_game *game)
{
    t_tile  **tilemap;
    int     x;
    int     y;

    tilemap = alloc_tilemap(map);
    if (!tilemap)
        return (error("malloc faild ! ps : alloc_tilemap() !"));
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            tilemap[y][x].type = define_tiletype(map[y][x]);
            setup_tile(tilemap, x, y);
        }
    }
}