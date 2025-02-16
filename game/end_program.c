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
    t_enemy *next = NULL;
    while(head)
    {
        next = head->next;
        free (head);
        head = next;
    }
}

void    free_list(t_list **head)
{
    t_list *next;

    next = NULL;
    while (head)
    {
        next = (*head)->next;
        free(head);
        *head = next;
    }
}

int end_program(t_game *game)
{
    free_tilemap(game);
    game->tilemap = NULL;
    free_enemies(game);
    game->enemy_list = NULL;
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free_list(game->head);
    free(game->mlx);
    exit(0);
}