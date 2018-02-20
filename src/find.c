/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:22:38 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 16:34:55 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos	find_top(const t_map *map, char player)
{
	t_pos	curr;

	curr.y = 0;
	while (curr.y < map->height)
	{
		curr.x = 0;
		while (curr.x < map->width)
		{
			if (map->data[curr.y][curr.x] == player)
				return (curr);
			curr.x++;
		}
		curr.y++;
	}
	return (curr);
}

t_pos	find_bot(const t_map *map, char player)
{
	t_pos	curr;

	curr.y = map->height;
	while (curr.y-- > 0)
	{
		curr.x = 0;
		while (curr.x < map->width)
		{
			if (map->data[curr.y][curr.x] == player)
				return (curr);
			curr.x++;
		}
	}
	return (curr);
}

t_pos	find_left(const t_map *map, char player)
{
	t_pos	curr;

	curr.x = 0;
	while (curr.x < map->width)
	{
		curr.y = 0;
		while (curr.y < map->height)
		{
			if (map->data[curr.y][curr.x] == player)
				return (curr);
			curr.y++;
		}
		curr.x++;
	}
	return (curr);
}

t_pos	find_right(const t_map *map, char player)
{
	t_pos	curr;

	curr.x = map->width;
	while (curr.x-- > 0)
	{
		curr.y = 0;
		while (curr.y < map->height)
		{
			if (map->data[curr.y][curr.x] == player)
				return (curr);
			curr.y++;
		}
	}
	return (curr);
}

t_meta	find_all(const t_map *map, char player)
{
	t_meta	meta;

	meta.top = find_top(map, player);
	meta.bot = find_bot(map, player);
	meta.right = find_right(map, player);
	meta.left = find_left(map, player);
	return (meta);
}
