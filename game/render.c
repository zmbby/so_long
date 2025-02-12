#include "game.h"

static void draw_image(t_tile tile, t_game game, t_vector pos)
{
    // ft_printf("x = %d | y = %d\n", pos.x, pos.y);
    if (tile.type == WALL)
        draw_wall(tile, game, pos);
    else if (tile.type == EXIT)
    {
        if (game.collects)
            mlx_put_image_to_window(game.mlx, game.win,
                game.door_open_img, pos.x, pos.y);
        if (game.collects == 0)
            mlx_put_image_to_window(game.mlx, game.win,
                game.door_close_img, pos.x, pos.y);
    }
    else if (tile.type ==  COIN)
        mlx_put_image_to_window(game.mlx, game.win,
            game.collects_imgs.current_img, pos.x, pos.y);
    else if (tile.type == PLAYER)
        mlx_put_image_to_window(game.mlx, game.win,
            game.player.current_img, pos.x, pos.y);
    else if (tile.type == ENEMY)
        mlx_put_image_to_window(game.mlx, game.win,
            game.enemy_imgs.basic_current, pos.x, pos.y);
    else if (tile.type == FOLLOWER)
        mlx_put_image_to_window(game.mlx, game.win,
            game.enemy_imgs.follow_current, pos.x, pos.y);
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
            x++;
        }
        y++;
    }
}