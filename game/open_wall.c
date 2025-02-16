#include "game.h"

void    open_walls_up(t_game *game)
{
    game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx, 
            "sprites/wall_02.xpm",
            &game->img_size.x, &game->img_size.y);
    game->wall_imgs.up_left = mlx_xpm_file_to_image(game->mlx,
            "sprites/wall_ul.xpm",
            &game->img_size.x, &game->img_size.y);
    game->wall_imgs.up = mlx_xpm_file_to_image(game->mlx,
            "sprites/wall_u.xpm",
            &game->img_size.x, &game->img_size.y);
    game->wall_imgs.up_right = mlx_xpm_file_to_image(game->mlx,
            "sprites/wall_ur.xpm",
            &game->img_size.x, &game->img_size.y);
    game->wall_imgs.right = mlx_xpm_file_to_image(game->mlx,
            "sprites/wall_r.xpm",
            &game->img_size.x, &game->img_size.y);
}

void	open_wallimgs_down(t_game *game)
{
	game->wall_imgs.down_right = mlx_xpm_file_to_image(game->mlx,
		"sprites/wall_dr.xpm",
		&game->img_size.x, &game->img_size.y);
	game->wall_imgs.down = mlx_xpm_file_to_image(game->mlx,
	        "sprites/wall_d.xpm",
		&game->img_size.x, &game->img_size.y);
	game->wall_imgs.down_left = mlx_xpm_file_to_image(game->mlx,
		"sprites/wall_dl.xpm",
		&game->img_size.x, &game->img_size.y);
	game->wall_imgs.left = mlx_xpm_file_to_image(game->mlx,
		"sprites/wall_l.xpm",
		&game->img_size.x, &game->img_size.y);
}

void    end_game_imgs(t_game *game)
{
        game->endgame.win_vec.x = 768;
        game->endgame.win_vec.y = 432;
        game->endgame.you_win_img = mlx_xpm_file_to_image(game->mlx,
                "sprites/you_win.xpm", &game->endgame.win_vec.x, &game->endgame.win_vec.y);
}