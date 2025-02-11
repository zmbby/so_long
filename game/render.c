#include "game.h"

static void draw_image(t_tile tile, t_game game, t_vector pos)
{
    if (tile.type == WALL)
        draw_wall(tile, game, pos);
}

void    render(t_game game)
{
    t_tile  tile;
    int     x;
    int     y;

    mlx_clear_window(game.mlx, game.win);
    y = 0;
    while (game.tilemap[y])
    {
        x = 0;
        while (game.tilemap[y][x].type)
        {
            tile = game.tilemap[y][x];
            draw_image(tile, game, tile.position);
        }
    }
}