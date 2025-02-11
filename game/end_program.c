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
    t_enemy *head = game->enemy_list;
    t_enemy *next;
    while(head)
    {
        next = head->next;
        free (head);
        head = next;
    }
}

int end_program(t_game *game)
{
    free_tilemap(game);
    game->tilemap = NULL;
    // free_enemies(game);
    // game->enemy_list = NULL;
    exit(0);
}