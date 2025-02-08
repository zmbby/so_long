
#include "../so_long.h"

t_tile  **map_init(int ac, char **av, t_game *game)
{
    char    **map;
    t_tile  **tilemap;

    if (!valid_file(ac, av[1]))
        return (NULL);
    map = read_map(av[1]);
    if (!map)
        return (NULL);
    if (!valid_map(map))
    {
        ft_free_chartable(map);
        return (NULL);
    }
    tilemap = generate_tilemap(map, game);
    return (tilemap);
}

int start(t_game *game, int ac, char **av)
{
    game->collects = 0;
    game->moves = 0;
    game->tilemap = map_init(ac, av, game);
    return (1);
}