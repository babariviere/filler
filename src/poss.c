/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:53:15 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 18:24:47 by briviere         ###   ########.fr       */
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

static int	calc_dist(t_pos *p1, t_pos *p2)
{
	return (ft_abs(p2->y - p1->y) + ft_abs(p2->x - p1->x));
}

static int	get_smallest_dist(t_pos *pos, t_meta en)
{
	int		cl;
	int		tmp;

	cl = calc_dist(pos, &en.top);
	if ((tmp = calc_dist(pos, &en.bot)) < cl)
		cl = tmp;
	if ((tmp = calc_dist(pos, &en.left)) < cl)
		cl = tmp;
	if ((tmp = calc_dist(pos, &en.right)) < cl)
		cl = tmp;
	return (cl);
}

static int	is_closer(t_pos *best, t_pos *now, t_meta en)
{
	int		cl_best;
	int		cl_now;

	cl_now = get_smallest_dist(now, en);
	cl_best = get_smallest_dist(best, en);
	if (cl_now < cl_best)
		return (1);
	return (0);
}

t_pos		*get_best_poss(const t_map *map, const t_lst *poss, char p)
{
	t_pos	*best;
	t_pos	*tmp;
	t_meta	en;

	en = find_all(map, (p == 'X' ? 'O' : 'X'));
	best = poss->content;
	while (poss)
	{
		tmp = poss->content;
		if (is_closer(best, tmp, en))
			best = tmp;
		poss = poss->next;
	}
	return (best);
}
