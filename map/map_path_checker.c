/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:00:31 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/17 19:13:18 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	**copy_map(char **map, t_vector size)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (size.y + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < size.y)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
				free(map_copy[--i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	flood_fill(char **map, int x, int y, t_vector size)
{
	if (x < 0 || y < 0 || x >= size.x - 1 || y >= size.y || map[y][x] == '1'
		|| map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, size);
	flood_fill(map, x - 1, y, size);
	flood_fill(map, x, y + 1, size);
	flood_fill(map, x, y - 1, size);
}

static t_vector	find_player(char **map)
{
	t_vector	pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'P')
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

int	check_path(char **map)
{
	t_vector	size;
	t_vector	player_pos;
	char		**map_copy;
	t_vector	tmp;
	int			valid;

	size.x = ft_strlen(map[0]);
	size.y = ft_chartable_linecount(map);
	map_copy = copy_map(map, size);
	if (!map_copy)
		return (error("Memory allocation failed"));
	player_pos = find_player(map_copy);
	if (player_pos.x == -1)
		return (error("Player position not found"));
	flood_fill(map_copy, player_pos.x, player_pos.y, size);
	valid = 1;
	tmp.y = 0;
	while (map_copy[tmp.y] && valid)
	{
		tmp.x = 0;
		while (map_copy[tmp.y][tmp.x] && valid)
		{
			if (map_copy[tmp.y][tmp.x] == 'C' || map_copy[tmp.y][tmp.x] == 'E')
				valid = 0;
			tmp.x++;
		}
		tmp.y++;
	}
	tmp.y = 0;
	while (map_copy[tmp.y])
		free(map_copy[tmp.y++]);
	free(map_copy);
	if (!valid)
		return (error("Not all collectibles or exit are reachable"));
	return (1);
}
