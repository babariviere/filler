/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:24:23 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 18:25:27 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef enum	e_state {
	STATE_START,
	STATE_FIGHT,
	STATE_RENFORCE,
	STATE_PEACE,
}				t_state;

typedef struct	s_map {
	char	**data;
	int		width;
	int		height;
}				t_map;

t_map			*create_map(void);
void			update_map(t_map *map);
void			delete_map(t_map **map);

typedef struct	s_piece {
	char	**data;
	int		width;
	int		height;
}				t_piece;

t_piece			*create_piece(void);
void			delete_piece(t_piece **piece);

typedef struct	s_zone {
	int		x;
	int		y;
	int		width;
	int		height;
}				t_zone;

t_zone			*locate_player(const t_map *map, char player);

int				try_placing(const t_map *map, const t_piece *piece,
			t_pos pos, char player);

t_lst			*get_poss(const t_map *map, const t_piece *piece, char player);
t_pos			*get_best_poss(const t_map *map, const t_lst *poss,
		char player);

typedef struct	s_meta {
	t_pos	top;
	t_pos	bot;
	t_pos	right;
	t_pos	left;
}				t_meta;

t_pos			find_top(const t_map *map, char player);
t_pos			find_bot(const t_map *map, char player);
t_pos			find_left(const t_map *map, char player);
t_pos			find_right(const t_map *map, char player);
t_meta			find_all(const t_map *map, char player);

#endif
