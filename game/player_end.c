/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zm <zm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:49:14 by zm                #+#    #+#             */
/*   Updated: 2025/02/17 22:51:08 by zm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	kill_player(t_game *game, t_vector pos)
{
	game->player.tile = NULL;
	effect_anim(&game->effect, pos);
	mlx_put_image_to_window(game->mlx, game->win, game->red_panel, 0, 0);
	end_game(game, 0);
	end_program(game);
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
	end_game(game, 1);
	end_program(game);
}