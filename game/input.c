#include "game.h"

int move_to(t_game *game, t_tile *tile)
{
    if (tile->type == EMPTY)
        move_to_empty(game, tile);
    else if (tile->type == COIN) // ---------- not finished here player movment
}

int input(int key, t_game *game)
{
    int moved;

    if (key == ESC)
        end_program(game);
    if (game->player.tile == NULL)
        return (0);
    if (key == KEY_UP)
        moved = move_to(game, game->player.tile->up);
    return (1);
}