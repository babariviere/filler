/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:24:23 by briviere          #+#    #+#             */
/*   Updated: 2018/02/15 12:41:20 by briviere         ###   ########.fr       */
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
	size_t	width;
	size_t	height;
}				t_map;

t_map			*create_map(void);
void			update_map(t_map *map);
void			delete_map(t_map **map);

typedef struct	s_piece {
	char	**data;
	size_t	width;
	size_t	height;
}				t_piece;

t_piece			*create_piece(void);
void			delete_piece(t_piece **piece);

#endif
