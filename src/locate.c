/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:54:54 by briviere          #+#    #+#             */
/*   Updated: 2018/02/15 13:16:38 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	find_set_pos(const t_map *map, t_zone *zone, char player)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	zone->x = -1;
	zone->y = -1;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == player && zone->y == -1)
				zone->y = y;
			if (map->data[y][x] == player && (x < zone->x ||
					zone->x == -1))
				zone->x = x;
			x++;
		}
		y++;
	}
}

static void	find_set_size(const t_map *map, t_zone *zone, char player)
{
	int		x;
	int		y;

	x = zone->x;
	y = zone->y;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == player && (y - zone->y + 1) > zone->height)
				zone->height = y - zone->y + 1;
			if (map->data[y][x] == player && (x - zone->x + 1) > zone->width)
				zone->width = x - zone->x + 1;
			x++;
		}
		y++;
	}
}

t_zone		*locate_player(const t_map *map, char player)
{
	t_zone	*zone;

	if ((zone = ft_memalloc(sizeof(t_zone))) == 0)
		return (0);
	find_set_pos(map, zone, player);
	find_set_size(map, zone, player);
	return (zone);
}
