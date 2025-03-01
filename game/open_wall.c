/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:05:56 by zoentifi          #+#    #+#             */
/*   Updated: 2025/03/01 15:15:29 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	open_walls_up(t_game *game)
{
	game->wall_imgs.block = load_xpm(game, "textures/wall_02.xpm");
	game->wall_imgs.up_left = load_xpm(game, "textures/wall_ul.xpm");
	game->wall_imgs.up = load_xpm(game, "textures/wall_u.xpm");
	game->wall_imgs.up_right = load_xpm(game, "textures/wall_ur.xpm");
	game->wall_imgs.right = load_xpm(game, "textures/wall_r.xpm");
}

void	open_wallimgs_down(t_game *game)
{
	game->wall_imgs.down_right = load_xpm(game, "textures/wall_dr.xpm");
	game->wall_imgs.down = load_xpm(game, "textures/wall_d.xpm");
	game->wall_imgs.down_left = load_xpm(game, "textures/wall_dl.xpm");
	game->wall_imgs.left = load_xpm(game, "textures/wall_l.xpm");
}
