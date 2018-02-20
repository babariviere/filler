/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:24:27 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 15:43:43 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_placing(char map_c, char piece_c, char player, int *over)
{
	if (map_c != player && map_c != '.' &&
			piece_c == '*')
		return (0);
	else if (map_c == player && piece_c == '*'
			&& *over)
		return (0);
	else if (map_c == player && piece_c == '*')
		*over = 1;
	return (1);
}

int			try_placing(const t_map *map, const t_piece *piece, t_pos pos,
		char player)
{
	int		override_one;
	int		x;
	int		y;

	override_one = 0;
	if (pos.y < 0 || pos.x < 0 || (pos.x + piece->width) >= map->width ||
			(pos.y + piece->height) >= map->height)
		return (0);
	y = pos.y;
	while (y < (pos.y + piece->height))
	{
		x = pos.x;
		while (x < (pos.x + piece->width))
		{
			if (!check_placing(map->data[y][x],
						piece->data[y - pos.y][x - pos.x],
						player, &override_one))
				return (0);
			x++;
		}
		y++;
	}
	return (override_one);
}
