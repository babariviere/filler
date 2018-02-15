/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:24:27 by briviere          #+#    #+#             */
/*   Updated: 2018/02/15 13:38:26 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		try_placing(const t_map *map, const t_piece *piece, t_pos pos,
		char player)
{
	int		override_one;
	int		x;
	int		y;
	char	piece_block;

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
			piece_block = piece->data[y - pos.y][x - pos.x];
			if (map->data[y][x] == player && piece_block == '*'
					&& override_one)
				return (0);
			else if (map->data[y][x] == player && piece_block == '*')
				override_one = 1;
			x++;
		}
		y++;
	}
	return (override_one);
}
