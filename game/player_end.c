#include "game.h"

void    you_win_lose(int i)
{
    if (i == 1)
    {
        ft_printf("----------------------------/*_!_*\\---------------------------------\n");
        ft_printf(" __     ______  _    _  __          _______ _   _   _ \n");
        ft_printf(" \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | | | |\n");
        ft_printf("  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| | | |\n");
        ft_printf("   \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` | | |\n");
        ft_printf("    | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  | |_|\n");
        ft_printf("    |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_| (_)\n");
        ft_printf("----------------------------/*!-!-!*\\---------------------------------\n");
        ft_printf("Congratulations! You Win!\n");
    }
    else
    {
        ft_printf("-----------------------------------------------------------------\n");
        ft_printf(" __     ______  _    _   _      ____   _____ ______   _ \n");
        ft_printf(" \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____| | |\n");
        ft_printf("  \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__    | |\n");
        ft_printf("   \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|   | |\n");
        ft_printf("    | | | |__| | |__| | | |___| |__| |____) | |____  |_|\n");
        ft_printf("    |_|  \\____/ \\____/  |______\\____/|_____/|______| (_)\n");
        ft_printf("-----------------------------------------------------------------\n");
        ft_printf("Oops! You Lose!\n");
    }
}

void    kill_player(t_game *game, t_vector pos)
{
    game->player.tile = NULL;
    effect_anim(&game->effect, pos);
    mlx_put_image_to_window(game->mlx, game->win,
        game->red_panel, 0, 0);
    you_win_lose(0);
    end_game(game, 0);
    end_program(game);
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
    you_win_lose(1);
    end_game(game, 1);
    end_program(game);
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