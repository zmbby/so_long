/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:02:13 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/09 16:25:39 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "../so_long.h"
#include "../map/map.h"

/**/
// game function

t_tile  **map_init(int ac, char **av, t_game *game);
int start(t_game *game, int ac, char **av);
int end_program(t_game *game);
void	open_image(t_game *game);
void    open_walls_up(t_game *game);
void    color_panel(t_panel *panel, t_color color);
void    *new_panel(t_game *game, t_color color);
t_color new_color(int r, int g, int b, int a);
#endif