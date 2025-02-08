#include "../so_long.h"
#include "game.h"

void    free_tilemap(t_game *game)
{
    t_tile  **tilemap;

    tilemap = game->tilemap;
    while(*game->tilemap != NULL)
    {
        free(*game->tilemap);
        game->tilemap++;
    }
    free (tilemap);
}

void    free_enemies(t_game *game)
{
    t_enemy *next;

    if (!game->enemy_list)
        return ;
    while(1)
    {
        next = game->enemy_list->next;
        free (game->enemy_list);
        if (!next)
            break;
        game->enemy_list = next;
    }
}

int end_program(t_game *game)
{
    free_tilemap(game);
    game->tilemap = NULL;
    free_enemies(game);
    game->enemy_list = NULL;
    exit(0);
}