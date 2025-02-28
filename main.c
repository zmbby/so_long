/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/02/18 15:19:57 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 15:19:57 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "map/map.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_game (game) = {0};
	if (!start(&game, ac, av))
		return (0);
	mlx_hook(game.win, KeyPress, KeyPressMask, input, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
