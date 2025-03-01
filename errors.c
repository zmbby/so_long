/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:22:01 by zoentifi          #+#    #+#             */
/*   Updated: 2025/03/01 15:15:29 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *msg)
{
	ft_printf("\033[0;31m"
		"Error \n%s\n"
		"\033[0m",
		msg);
	return (0);
}

/* Returns NULL printing <message> in red */
void	*null_error(char *message)
{
	ft_printf("\033[0;31m"
		"Error \n%s\n"
		"\033[0m",
		message);
	return (0);
}

/* Prints <message> in yellow */
void	print_warning(char *message)
{
	ft_printf("\033[0;33m"
		"Warning \n%s\n"
		"\033[0m",
		message);
}

void	cleanup_images(t_game *game)
{
	t_garbage	*current;
	t_garbage	*next;

	current = game->garbage_head;
	while (current)
	{
		next = current->next;
		if (current->img)
			mlx_destroy_image(game->mlx, current->img);
		free(current);
		current = next;
	}
	game->garbage_head = NULL;
}

void	end_game(t_game *game, int won)
{
	void	*end_img;
	int		w;
	int		h;

	mlx_clear_window(game->mlx, game->win);
	if (won == 1)
		end_img = mlx_xpm_file_to_image(game->mlx, "textures/you_win.xpm", &w,
				&h);
	else
		end_img = mlx_xpm_file_to_image(game->mlx, "textures/you_lose.xpm", &w,
				&h);
	int (x) = (game->win_size.x - w) / 2;
	int (y) = (game->win_size.y - h) / 2;
	if (end_img)
	{
		mlx_put_image_to_window(game->mlx, game->win, end_img, x, y);
		mlx_do_sync(game->mlx);
		sleep(1);
		mlx_destroy_image(game->mlx, end_img);
	}
	else if (won == 1)
		ft_printf("YOU WIN !\n");
	else
		ft_printf("YOU LOSE !\n");
	cleanup_images(game);
}
