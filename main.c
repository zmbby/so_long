#include "so_long.h"
#include "map/map.h"
#include "game/game.h"

//------------------16 line and 31 col is the limit dell machine

int main(int ac, char **av)
{
    t_game game = {0};
    if (!start(&game, ac, av))
        return (0);
    mlx_hook(game.win, KeyPress, KeyPressMask, input, (void *)&game);
    mlx_loop_hook(game.mlx, update, (void *)&game);
    // mlx_key_hook(game.win, input, (void *)&game);
    mlx_loop(game.mlx);
    return (0);
}
// int main()
// {
//     t_game game = {0}; 
//     add_enemy(&game, FOLLOW_ENEM, NULL);
//     add_enemy(&game, FOLLOW_ENEM, NULL);
//     add_enemy(&game, HORIZONTAL_ENEM, NULL);
//     int i = 0;
//     while (game.enemy_list)
//     {
//         i++;
//         game.enemy_list = game.enemy_list->next;
//     }
//     printf("-------%d--\n", i);
// }
// #include <mlx.h>
// #include <stdio.h>

// typedef struct s_data {
//     void    *mlx;
//     void    *win;
// }               t_data;

// int key_press(int keycode, t_data *data)
// {
//     printf("Key pressed: %d\n", keycode);
//     return (0);
// }

// int main(void)
// {
//     t_data data;

//     data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, 800, 600, "Keycode Detector");

//     mlx_key_hook(data.win, key_press, &data);

//     mlx_loop(data.mlx);
//     return (0);
// }
