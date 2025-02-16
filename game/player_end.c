#include "game.h"

void    kill_player(t_game *game, t_vector pos)
{
    game->player.tile = NULL;
    effect_anim(&game->effect, pos);
    mlx_put_image_to_window(game->mlx, game->win,
        game->red_panel, 0, 0);
    // end_program(game);
}

void    remove_player(t_game *game)
{
    game->player.tile->type = EMPTY;
    game->player.tile = NULL;
    // end_program(game);
}