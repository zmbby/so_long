/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:15:04 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 17:55:17 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	pick_coin(t_game *game, t_tile *tile)
{
	tile->type = EMPTY;
	game->collects--;
	effect_anim(&game->effect, tile->position);
	action_anim(&game->player);
}

void	move_to_exit(t_game *game, t_tile *tile)
{
	effect_anim(&game->effect, tile->position);
	mlx_put_image_to_window(game->mlx, game->win, game->white_panel, 0, 0);
	remove_player(game);
	game->collects = -1;
}

void	move_to_enemy(t_game *game, t_tile *tile)
{
	kill_player(game, tile->position);
	effect_anim(&game->effect, tile->position);
	mlx_put_image_to_window(game->mlx, game->win, game->red_panel, 0, 0);
}
