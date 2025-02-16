#include "game.h"
void    effect_anim(t_effect *effect, t_vector pos)
{
    effect->counter = 0;
    effect->pos = pos;
}

void    action_anim(t_player *player)
{
    player->framecount = 0;
    player->current_img = player->action_img;
}

int move_to(t_game *game, t_tile *tile)
{
    if (tile->type == COIN)
        pick_coin(game, tile);
    else if (tile->type == EXIT && game->collects <= 0)
        move_to_exit(game, tile);
    if (tile->type == EMPTY)
        move_to_empty(game, tile);
    else if (tile->type == ENEMY || tile->type == FOLLOWER)
    {
        move_to_enemy(game, tile);
        return (0);
    }
    else if (tile->type == WALL)
        return (0);
    // move_follower(game);
    return (1);
}

int input(int key, t_game *game)
{
    int moved;
    // (void)moved;
    if (key == ESC)
        end_program(game);
    if (game->player.tile == NULL)
        return (0);
    if (key == KEY_UP)
        moved = move_to(game, game->player.tile->up);
    else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved)
		ft_printf("Moves -> %d\n", game->moves++);
    return (1);
}