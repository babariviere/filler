/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:53:15 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 15:33:09 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_lst		*get_poss(const t_map *map, const t_piece *piece, char player)
{
	t_lst		*poss;
	t_pos		curr_pos;
	t_zone		*pl;
	int			x;

	pl = locate_player(map, player);
	x = pl->x - piece->width;
	curr_pos = (t_pos){x, pl->y - piece->height};
	poss = 0;
	while (curr_pos.y < (pl->y + pl->height))
	{
		curr_pos.x = x;
		while (curr_pos.x < (pl->x + pl->width))
		{
			if (try_placing(map, piece, curr_pos, player))
				ft_lstpush(&poss, ft_lstnew(&curr_pos, sizeof(t_pos)));
			curr_pos.x++;
		}
		curr_pos.y++;
	}
	free(pl);
	return (poss);
}
