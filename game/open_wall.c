#include "game.h"

void    open_walls_up(t_game *game)
{
    game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx, 
            "sprites/wall_02.xpm",
            &game->img_size.x, &game->img_size.y);
    // game->wall_imgs.up_left
}