#include "game.h"

int input(int key, t_game *game)
{
    int moved;
    (void)moved;
    if (key == ESC)
        end_program(game);
    return (1);
}