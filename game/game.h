/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:02:13 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/08 19:47:15 by zoentifi         ###   ########.fr       */
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
#endif