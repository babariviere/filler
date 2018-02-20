/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:39:58 by briviere          #+#    #+#             */
/*   Updated: 2018/02/20 15:32:14 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		fill_size(char *buf, t_piece *piece)
{
	while (*buf && !ft_iswhitespace(*buf))
		buf++;
	if (*buf == 0)
		return ;
	buf++;
	piece->height = ft_atoi(buf);
	buf += ft_numlen(piece->height);
	if (*buf == 0 || !ft_iswhitespace(*buf))
		return ;
	buf++;
	piece->width = ft_atoi(buf);
}

t_piece		*create_piece(void)
{
	t_piece	*piece;
	char	*buf;
	int		idx;

	if ((piece = ft_memalloc(sizeof(t_piece))) == 0)
		return (0);
	if (ft_gnl(0, &buf) <= 0)
		return (0);
	fill_size(buf, piece);
	free(buf);
	if ((piece->data = ft_memalloc(sizeof(char *) * (piece->height + 1))) == 0)
		return (0);
	idx = 0;
	while (idx < piece->height)
	{
		if (ft_gnl(0, &buf) <= 0)
			return (0);
		piece->data[idx++] = buf;
	}
	return (piece);
}

void		delete_piece(t_piece **piece)
{
	t_piece	*tmp;
	int		idx;

	tmp = *piece;
	if (tmp->data)
	{
		idx = 0;
		while (idx < tmp->height)
			ft_strdel(&tmp->data[idx++]);
		ft_memdel((void **)&tmp->data);
	}
	ft_memdel((void **)piece);
}
