/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <zoentifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:55:22 by zoentifi          #+#    #+#             */
/*   Updated: 2025/02/18 18:21:02 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'H'
		|| c == 'V' || c == 'F' || c == '\n')
		return (1);
	return (0);
}

int	valid_uniquechar(char c, int *b_player)
{
	if (c == 'P' && *b_player == 0)
		*b_player = 1;
	else if (c == 'P' && *b_player == 1)
		return (0);
	return (1);
}

static int	is_full_wall_row(char *row)
{
	int	i;

	i = 0;
	while (row[i] && row[i] != '\n')
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_border(char **map, t_vector size)
{
	int	y;

	if (!is_full_wall_row(map[0]) || !is_full_wall_row(map[size.y - 1]))
		return (0);
	y = 1;
	while (y < size.y - 1)
	{
		if (map[y][0] != '1' || map[y][size.x - 2] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	ft1(char c)
{
	if (c == 'C' || c == 'E')
		return (1);
	return (0);
}
