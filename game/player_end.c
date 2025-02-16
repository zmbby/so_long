#include "game.h"

void    kill_player(t_game *game, t_vector pos)
{
    game->player.tile = NULL;
    effect_anim(&game->effect, pos);
    mlx_put_image_to_window(game->mlx, game->win,
        game->red_panel, 0, 0);
    // game->counter = 1;
    // while (game->counter)
    // {
    //     if (game->counter == 60)
    //     {
    //         // mlx_clear_window(game->mlx, game->win);
    //         mlx_put_image_to_window(game->mlx, game->win, game->endgame.you_win_img, 0, 0);
    //         sleep(5);
    //         // end_program(game);
    //     }
    //     game->counter++;            
    // }
}

void    remove_player(t_game *game)
{
    game->player.tile->type = EMPTY;
    game->player.tile = NULL;
    // mlx_clear_window(game->mlx, game->win);
    // mlx_put_image_to_window(game->mlx, game->win, game->endgame.you_win_img, 0, 0);

    // game->counter = 1;
    // while (game->counter)
    // {
    //     if (game->counter == 60000)
    //         end_program(game);
    //     game->counter++;            
    // }
}